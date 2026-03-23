#!/bin/bash

if [[ $# -lt 2 ]]; then
	echo "il manque le fichier et le nombre entier"
	exit 1
fi

if [[ $1 = "-b" ]]; then

	opt=$1
	fichier=$2
	nb=$3

else
	fichier=$1
	nb=$2
fi

users=$( cat $fichier | wc -l )

for (( i=1; i <= $users; i++ ));
do 	
	$(mkdir "groupe$i")
	for (( j=1; j <= $nb; j++));
	do
		
		
	
	
