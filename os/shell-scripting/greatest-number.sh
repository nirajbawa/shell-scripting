#!/bin/bash

# Write a shell script to find the largest number among 3 numbers and write the results 
# in file. (Make use of redirection operator and join commands to write the results in file)

output="output.txt"
>"$output"

read -p "enter num 1 : " num1
read -p "enter num 2 : " num2
read -p "enter num 3 : " num3



{
if [[ num1 -gt num2 && num1 -gt num3 ]];
then 
    echo "num1 ($num1) is largest number"
elif [[ num2 -gt num3 ]];
then    
    echo "num2 ($num2) is largest number"
else
    echo "num3 ($num3) is largest number"
fi
} >> "$output"


