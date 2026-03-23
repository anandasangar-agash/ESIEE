#!/bin/bash

if test -z "$1"; then 
    echo "Veuillez entrer un entier en paramètre"
fi



for (( i = 0; i <= "$1" ; i++ )) ; do 

    echo "$i"
    sleep 1

done 
exit 0