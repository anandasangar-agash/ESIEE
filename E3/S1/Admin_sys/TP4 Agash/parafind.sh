#!/bin/bash

if [ "$#" -eq 0 ]; then
    echo "Veuillez passer un argument"
    exit 1
fi

# Initialiser l'index
index=0

# Déclarer un tableau pour stocker les PID
declare -a pids

# Boucle sur chaque répertoire donné en argument
for dir in "$@"; do
    index=$((index + 1))

    echo "$dir"
    
    # Fichiers de sortie
    out="/tmp/find-$index.txt"
    log="/tmp/find-$index.log"

    # Lancer la commande find en arrière-plan
    find "$dir" -type d > "$out" 2> "$log" &
    
    pid=$!
    echo "J’attends le PID $pid"
    pids[$index]=$pid
done

# Compter les erreurs
error_count=0

# Attendre que chaque commande se termine
for idx in "${!pids[@]}"; do
    pid=${pids[$idx]}
    wait "$pid"
    status=$?
    if [ "$status" -ne 0 ]; then
        error_count=$((error_count + 1))
    fi
done

exit "$error_count"