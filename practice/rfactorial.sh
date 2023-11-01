#!/bin/bash

factorial()
{
	local i=$1
	local f
	if [ $i -le 2 ]; then
		echo $i
	else
		let f=$( i - 1)
		let f=$(factorial $f)
		let f=$(( f * i ))
		echo $f
	fi
}

if [ $# -eq 0 ]; then
	echo"Usage:need a number for input"
	exit 1
fi
factorial $1
exit 0
