#!/bin/bash

if [ $# -eq 0 ]; then
	echo "you need to pass one numerical value"
	exit 1
fi
#if ! [ "$1" -eq ^[0-9]+$ ]; then
#	echo "you need a numerical value"
#	exit 1
#fi
number=$1
sum=0
re='^[0-9]+$'
if ! [[ $number =~ $re ]]; then
	printf "not a number."
	exit 1
fi
	while [ $number -gt 0 ]; 
	do
		n=`expr $number % 10`
		sum=`expr $sum + $n`
		number=`expr $number / 10`

	done

echo "$sum is your numbers individually digits added up"
exit 0
