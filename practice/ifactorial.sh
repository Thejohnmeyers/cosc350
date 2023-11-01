#!/bin/bash
factorial(){
	local result=1
	for i in $(seq 1 $1); do
		let result=result*$i
	done
	return $result
}

if [ $# -eq 0 ]; then
	echo"Usage: need a number for input"
	exit 1
fi
factorial $1
echo $?
exit 0
