#!/bin/bash
echo "enter first number"
read a
echo "enter second number"
read b
sum=$((a+b))
echo "average : $((sum/2))"
echo "product : $((a*b))"   
echo "Before Swapping : $a   $b"
#swapping
a=$((a+b))
b=$((a-b))
a=$((a-b))
echo "After Swapping :  $a   $b"
