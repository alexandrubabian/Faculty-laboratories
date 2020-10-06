#!/bin/bash

file=$(mktemp /tmp/script.XXXXXX)
for i in *.c
do
	aux=$(head -3 $i) 
	echo $aux>>file
done
cat file
rm -f file
