#!/bin/bash

if [ $# -ne 1 ]; then
    echo "Il manque un argument"
    exit 1
fi

rep="$1"

# Vérification que c'est bien un répertoire
if [ ! -d "$rep" ]; then
    echo "Erreur : $rep n'est pas un répertoire."
    exit 1
fi

# Boucle sur tous les fichiers du répertoire (pas les sous-répertoires)
for fichier in "$rep"/*; do
    # Ignorer s'il ne s'agit pas d'un fichier
    if [ ! -f "$fichier" ]; then
        continue
    fi

    # Extraire nom et extension
    nom_fichier=$(basename "$fichier")
    
    # Extraction de l'extension : tout ce qui suit le dernier point
    ext="${nom_fichier##*.}"
    # Extraction de l'extension : tout ce qui vient avant le point
    nom_sans_ext="${nom_fichier%.*}"

    echo -n "Je traite $fichier -> "
    # Gestion des cas où il n'y a pas d'extension (le nom complet = nom_sans_ext)
    if [ "$nom_fichier" = "$nom_sans_ext" ]; then
        # Pas d'extension
        echo "mv $fichier $rep $nom_sans_ext.jpg\""
    else
        # Il y a une extension, on teste si c'est jpg (en minuscule)
        # Convertir l'extension en minuscules pour la comparaison
        ext_min=$(echo "$ext" | tr 'A-Z' 'a-z')
        if [ "$ext_min" = "jpg" ]; then
            # Extension correcte
            echo "est OK, rien à lancer"
        else
            # Extension incorrecte, on remplace par .jpg
            echo "mv $fichier $rep $nom_sans_ext.jpg\""
        fi
    fi
done
