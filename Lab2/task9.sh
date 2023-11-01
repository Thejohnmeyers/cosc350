#!/bin/bash
cd
echo "enter a directory to find your file in: "
read direct
if [ -d $direct ]; then
	echo "This is a directory"
else
	echo "This is not a directory"
	exit 1
fi
cd $direct
count=0
while [ $count -ne 3 ];
do
	echo "enter a file name you are searching for: "
	read file
	if [ -f $file ]; then
		echo "file found!"
		break
	
	elif [ ! -f $file ]; then
		echo "unsuccessful file search please try again"
		count=`expr $count + 1`
	fi
done
if [ $count -eq 3 ]; then
	echo "Too many attempts at finding a file goodbye"
	exit 2
fi
if [ ! -r $file ]; then
	echo "File is not readable"
	exit 3
fi
echo "enter a word to be found within the selected file: "
read word
exists=$(grep -c $word $file)
if [ $exists -ne 0 ]; then
	echo "FOUND!"
	exit 0
else
	echo "NOT FOUND"
	exit 4
fi

