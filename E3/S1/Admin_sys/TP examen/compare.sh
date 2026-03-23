#!/bin/bash

if [[ $# -ne 2 ]]; then
	echo "Utilisation : compare mot1 mot2"
	exit 1
fi

mot1=$1
mot2=$2

echo "$mot1 $mot2"

if [[ $mot2 =~ $mot1 ]];
then
	echo "Les deux mots sont identiques"
	exit 2
else
	echo "$mot2"
	exit 0
fi
