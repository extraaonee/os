#!/bin/bash
echo "enter number of terms : "
read n
  f0=0
  f1=1
  i=2
  echo "Fibonacci Series up to $n terms :"
  echo "$f0"
  echo "$f1"
  while [ $i -lt $n ]
  do
      i=$((i + 1))
      fn=$((f0 + f1))
      echo "$fn"
      f0=$f1
      f1=$fn
  done
