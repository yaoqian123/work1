#! /bin/bash

function seqmy
{
	if [ $# -eq 0 ]
	then
		echo `seqmy缺少操作数`
	elif[ $# -gt 3]
	then
		echo `seqmy额外操作数$4`
	elif[ $# -eq 1]
	then
		for((i=1;i<$1;i++))
		do
			echo $1
		done
	elif[ $# -eq 2]
	then
		for(( i=1;i<=$2;i++ ))
		do
			echo $2
		done
	elif[ $# -eq 3 ]
		for((i=$i;i<$2;i++))
		do
			echo $2
		done
	fi
}
seqmy 1 2 3 4 5
