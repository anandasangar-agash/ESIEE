#!/bin/bash

if [[ $# -ne 3 ]]; then
    echo "Il faut entrer l'opérateur et deux nombres"
    exit 1
fi

op="$1"
a="$2"
b="$3"

if [[ ! "$a" =~ ^-?[0-9]+(\.[0-9]+)?$ || 
! "$b" =~ ^-?[0-9]+(\.[0-9]+)?$ ]] ; then
    echo "Il faut entrer des nombres"
    exit 1
fi

case $op in
    +) r=$(( a + b ));;
    -) r=$(( a - b ));;
    \*) r=$(( a * b ));;
    /) [ "$b" = "0" ] && { echo "Erreur: division par zéro"; exit 1; }; r=$(( a / b ));;
    *) echo "Erreur: opérateur inconnu"; exit 1;;
esac

echo "$a $op $b = $r"
exit 0