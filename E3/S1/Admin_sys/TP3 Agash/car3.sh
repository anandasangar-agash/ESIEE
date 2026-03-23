#!/bin/bash

if [[ $# -ne 1 ]];
then
        echo "Saisir un argument"
        exit 1
fi

case $1 in
  ???)
        echo "OK"
        ;;
  ????*)
        echo "Trop de caractères"
        exit 2
        ;;
  *);;
esac
