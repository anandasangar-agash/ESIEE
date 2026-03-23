#!/bin/bash
# La commande shift dans ce code permet d'avancer dans les arguments, 
# par exemple après la première boucle, $2 devient $1   

> "$1"
fichier="$1"

while test "$1" && test "$2"; do
    
    rep="$2"

    if [ -d "$rep" ]&& [ -r "$rep" ]; then
        nb=$(ls "$rep" 2>/dev/null | wc -l)
        echo "Il y a $nb fichiers dans $rep" >> "$fichier"
    fi
shift
done