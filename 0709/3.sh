#! /bin/bash

array=(1 3 2 45 6 3 4 7 6 8 9 0 10)
a=0
b=0
c=0
for i in ${array[@]}
do
	if [ $i -gt $b ]
	then
		b=$i
		if [ $b -gt $a ]
		then
			c=$a
			a=$b
			b=$c			
		fi
	fi
done
echo $a $b
	
