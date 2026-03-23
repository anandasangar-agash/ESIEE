#!/bin/bash

if test -z $1; then
    echo "Il n'y a pas d'arguments"
    exit 1 
fi

if test -d $1; then
    nb=$(ls $1 | wc -l)
    if test $nb = 0; then
        echo "Voulez-vous le supprimer (o/n) ?"
        read rep
        if [[ $rep == o ]]; then
            echo "rmdir $1"
            rmdir $1
            exit 0
        elif [[ $rep == n ]]; then
            echo "non"
            exit 0
        fi
    else
        echo "Le répertoire n'est pas vide"
        exit 0
    fi

else
    echo "$1 n'est pas un répertoire"
    exit 1
fi