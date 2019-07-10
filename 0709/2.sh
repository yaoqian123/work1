#! /bin/bash

array=(1 5 3 4 8 9 7 6 12 57 15 34 18)
read key
a=0
#for i in ${array[@]}
for((i=0;i<13;i++))
do
	if [ ${key} -eq ${array[i]} ]
	then
		echo "存在KEY!"
		a=1
 		break
	fi
done
if [ $a -eq 0 ]
then
	echo "不存在"
fi
