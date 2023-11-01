#!/bin/bash

factorial(){
	local result=1
	local i=$1
	while [ $i != 1 ];
	do
		result=$(expr "$result" \* "$i")
		i=`expr $i - 1`
		
	done
	echo $result
}
if [ $# -eq 0 ]; then
	echo " need input"
	exit 1
fi
factorial $1
#sum=$(factorial $1)
#echo $sum
exit 0
