#!/bin/bash
echo "enter any integer"
read a
ans=$(($a % 2))
if [ $ans -eq 0 ]
then
  echo "$a is even number"
else
  echo "$a is odd number"
fi
