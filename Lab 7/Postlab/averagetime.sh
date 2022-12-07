#!/bin/bash

#winston Zhang, wyz5rge
#averagetime.sh
#28 October 2021

read input
if [ $input == "quit" ]
then
    exit
fi

sum=0
for i in {1..4} ; do
    runtime=`./a.out $input`
    sum=$(($sum+$runtime))
done

avg=$((sum/5))
echo $avg
