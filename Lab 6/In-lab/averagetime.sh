#!/bin/bash

#Winston Zhang, wyz5rge
#averagetime.sh
#19 October 2021

read dictionary
read grid

runtime1=`./a.out $dictionary $grid | tail -1`
runtime2=`./a.out $dictionary $grid | tail -1`
runtime3=`./a.out $dictionary $grid | tail -1`
runtime4=`./a.out $dictionary $grid | tail -1`
runtime5=`./a.out $dictionary $grid | tail -1`

sum=$(($runtime1+$runtime2+$runtime3+$runtime4+$runtime5))
avg=$((sum/5))
echo $avg
