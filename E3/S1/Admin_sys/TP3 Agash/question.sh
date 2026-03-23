#!/bin/bash

echo "PID = $$"
echo -n $1
(sleep 5 && kill $$ 2>/dev/null)&
read rep
if [[ $rep == o  || $rep == O ]]; 
then
        exit 0
else
        exit 1
fi
