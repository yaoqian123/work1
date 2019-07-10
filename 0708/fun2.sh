#! /bin/bash

read path
count=0
lenth=0
for file in `ls $path`
do
	if [ ${#file} -gt ${#lenth} ]
	then
		lenth=$file
	fi
	count=`expr $count + 1`
done
echo $count $lenth
