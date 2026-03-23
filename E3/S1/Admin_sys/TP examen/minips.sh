#!/bin/bash

if test -z $1;
then 
	pid=$$
else 
	pid=$1
fi


Name=$(cat /proc/$pid/comm)
STATE=$(cat /proc/$pid/status | grep State)


echo "PID	NAME	STATE"
echo "$pid	$Name	${STATE[Status]}"

