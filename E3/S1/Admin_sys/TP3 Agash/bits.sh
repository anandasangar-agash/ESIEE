#!/bin/bash

octets=0

if [ -n "$1" ]; 
then
        a=$1
fi

while true;
do

        read -n 1 -p "Appuyez sur une entrée (q pour quitter) : " touche
        echo ""

        if [[ "$touche" == "q" ]]; then
                octets=$(( a / 8 ))
                echo "Ça fait $octets octets."
                break
        fi

        read -p "Saisir un nombre de bits : " bits

        if [ "$bits" -lt 0 ]; then
                echo "Erreur !"
                exit 1
        fi

        a=$(( a + bits ))

done
