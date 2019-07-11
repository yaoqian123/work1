#! /bin/bash

a=(1 2 3 4 5 6 7 8 9 10)
b=10
c=10
d=10
for i in ${a[@]}
do
	if [ $i -lt $b ]
	then
		b=$i
		if [ $b -lt $c ]
		then
			d=$c
			c=$b
			b=$d
		fi
	fi	
done
echo $c $b

