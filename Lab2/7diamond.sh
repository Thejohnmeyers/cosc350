#!/bin/bash

echo "what size do you want your diamond to be?"
read size
#reading user input


oddcheck=`expr $size % 2`
if [ $oddcheck -eq 0 ]; then
	echo "Need an odd integer"
	exit 1
fi
#checking if the number entered is odd
if [ $size -le 3 ]; then
	echo "Need a number greater than 3"
	exit 1
fi
#checking if the number entered is greater than 3
half=`expr $size + 1`
half=`expr $half / 2`
half=`expr $half - 1`
space=$size
count=1
#setting of variables and calculating half of the size
#-------- UPPER DIAMOND------------
for i in $(seq 1 $half)
do
	
	for k in $(seq $i $size)
	do
		printf " "
	done
	for j in $(seq $i $count)
	do
		printf "*"
	done
	count=`expr $count + 3`
	echo	
done
for i in $(seq 1 $half)
do
        printf " "
done
printf " "
#---------MIDDLE OF DIAMOND------------
for i in $(seq 1 $size)
do
	printf "*"
done
echo
count=`expr $count - 2`
space=`expr $space - 1`
size1=`expr $size + 2`
if [ $size -gt 5 ]; then
	hold=`expr $size - 5`
	hold=`expr $hold / 2`
	size1=`expr $size1 + $hold`
fi
#had issues with the spacing but figured out some arithmatic to calculate the spacing
#----------LOWER DIAMOND-----------
for i in $(seq $space -1 1)
do
	 if [ $(expr $i % 2) -eq "0" ]; then
		size1=`expr $size1 - 1`
	 	continue
	 fi

	for k in $(seq $i $size1)
	do 
		printf " "
	done
	
	for j in $(seq $i -1 1)
	do 
		printf "*"
	done	
	echo
done







exit 0
