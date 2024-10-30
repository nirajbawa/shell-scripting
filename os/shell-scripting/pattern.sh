#!/bin/bash

# Read the first 25 marks. Write a shell script to print the following pattern.( Make use of Make 
# use of control flow statements. Make use of redirection operator and join commands to write 
# the results in file) 
# 1
# 1 3
# 1 3 5
# 1 3 5 7

output="output.txt"
>"$output"

echo "enter first 25 marks : " 
read -a marks

if [[ ${#marks[@]} -ne 25 ]];
then 
    echo "please enter exactly 25 subjects marks"
    exit 1
fi

{
echo "\n\nyour entered numbers are : "
for num in "${marks[@]}";
do
    echo "$num"
done
} >> "$output"


{
echo "\n\npattern : "
for ((i=1; i<=4; i++));
do
    count=1
    for ((j=1; j<=i; j++));
    do 
        echo -n "$count "
        count=$((count+2))
    done
    echo
done
} >> "$output"