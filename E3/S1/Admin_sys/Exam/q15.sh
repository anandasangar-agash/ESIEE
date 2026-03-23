#!/bin/bash

if [ $# -eq 0 ]; then
    NMAX=100; MAX=10
elif [ $# -eq 2 ]; then
    NMAX=$1; MAX=$2
else
    echo "Usage: $0 [NMAX MAX_ATTEMPTS]" >&2; exit 1
fi

[[ ! $NMAX =~ ^[0-9]+$ || ! $MAX =~ ^[0-9]+$ ]] && { echo "Erreur: paramètres doivent être des nombres positifs" >&2; exit 1; }

TARGET=$((RANDOM % NMAX + 1))
attempt=0

echo "Devinez le nombre entre 1 et $NMAX. Vous avez $MAX tentatives."

while [ $attempt -lt $MAX ]; do
    ((attempt++))
    read -p "Tentative $attempt: " guess
    [[ ! $guess =~ ^[0-9]+$ ]] && { echo "Entrez un nombre valide."; ((attempt--)); continue; }

    if [ $guess -eq $TARGET ]; then
        echo "Tu as trouvé en $attempt tentatives !"
        read -p "Votre nom : " user
        echo "$user $attempt" >> scores.save
        exit 0
    fi

    [[ $guess -lt $TARGET ]] && echo "Plus" || echo "Moins"
done

echo "Le nombre était $TARGET."