#!/bin/bash

# Write a shell script that prompts the user to enter a string. The script should check if the 
# entered string is a palindrome (a string that reads the same forwards and backwards). It 
# should display an appropriate message indicating whether the string is a palindrome.


read -p "enter string : " str

len=${#str}

rev=""
for ((i=len; i>=0; i--))
do
    rev="$rev${str:$i:1}"
done


echo "reversed string : $rev"

if [[ $str == $rev ]];
then
    echo "string is palindrome"
else
    echo "string is not palindrome"
fi

# ./string-palindrome.sh > output.txt