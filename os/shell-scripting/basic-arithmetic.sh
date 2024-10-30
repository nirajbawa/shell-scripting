#!/bin/bash

# 5. 
# Write a shell script to perform basic arithmetic operations (addition, subtractíon. 
# multiplication, and division) of two numbers. 
# (Make use of redirection operator and join commands to write the results in file)



output="output.txt"
>"$output"

read -p "enter number a : " a
read -p "enter number b : " b


{
    echo "addition of $a + $b = $((a+b))"
    echo "subtraction of $a - $b = $((a-b))"
    echo "multiplication of $a * $b = $((a*b))"
    echo "division of $a / $b = $((a/b))"
    echo "mod of $a % $b = $((a%b))"
} >> "$output"
