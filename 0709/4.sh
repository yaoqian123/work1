#! /bin/bash

a=(1,2,3,4,5,7,9,12,15,17,19,21,30)
read n
b=0
low=0
high=12
mid=0
while [ $low -le $high ]
do
	mid=`expr \( $low + $high \) / 2`
	if [ ${a[$mid]} -eq $n ]
	then
		b=1
	echo "存在"
		break
	elif [ ${a[$mid]} -lt $n ]
	then
		low=`expr $mid + 1`
	else
		high=`expr $mid - 1`
	fi
done
if [ $b -eq 0 ]
then
	echo "不存在"
fi
