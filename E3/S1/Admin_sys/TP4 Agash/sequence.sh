#!/bin/bash

if test -z $2; then
    echo "Il n'y a pas 2 arguments"
    exit 1 
fi

t=1

if test $1 = "-c";then

    if test -z $4; then
        echo "Il n'y a pas 4 arguments"
        exit 1
    fi

    t=$2
    debut=$3
    fin=$4
else

    debut=$1
    fin=$2

fi

i=$debut
while [ $i -le $fin ]; do
    echo "$i"
    i=$((i + t))
done

