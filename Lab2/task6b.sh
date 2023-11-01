#!/bin/bash

echo "what size do you want the base of your arrow to be?"
read size
echo "how big do you want the tail to be?"
read tail
#reading user input


oddcheck=`expr $size % 2`
if [ $oddcheck -eq 0 ]; then
        echo "Need an odd integer"
        exit 1
fi
#checking if the number entered is odd
half=`expr $size + 1`
half=`expr $half / 2`
half=`expr $half - 1`
space=`expr $size - 1`
count=1
#setting of variables and calculating half of the size
#-------- UPPER ARROW------------
if [ $size -gt 5 ]; then
	sp=`expr $size - 5`
	sp=`expr $sp / 2`
	space=`expr $space + $sp`
fi
for i in $(seq 1 $half)
do

        for k in $(seq $i $space)
        do
                printf " "
        done
        for j in $(seq $i $count)
        do
                printf "*"
        done
        count=`expr $count + 3`
	space=`expr $space - 1`
        echo    
done
for i in $(seq 2 $half)
do
        printf " "
done

#---------MIDDLE OF ARROW------------
for i in $(seq 2 $size)
do
        printf "*"
done

for i in $(seq 1 $tail)
do
        printf "*"
done
echo
count=`expr $count - 2`
space=$size
space=`expr $space - 1`
size1=$size 
if [ $size -gt 5 ]; then
        hold=`expr $size - 5`
        hold=`expr $hold / 2`
        size1=`expr $size1 + $hold`
fi
#had issues with the spacing but figured out some arithmatic to calculate the spacing
#----------LOWER ARROW-----------
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
	size1=`expr $size1 + 1`
        echo
done




exit 0
