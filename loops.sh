#!/bin/bash

#for loop
n=10

for (( num=1; num <= $n; num++ ));
do
    echo "$num"
done 

echo -e "\n\n"

for num in {1..5};
do
    echo "$num"
done 

echo -e "\n\n"

for (( num=$1; num<=$2; num++ ));
do
    echo "$num"
done


echo -e "\n\n while : "

num=1
while [[ $num -lt 5 ]];
do 
    echo $num
    num=$((num+1))
done


echo -e "\n\n"

arr=("10" "hello" "3.14")
for item in "${arr[@]}"; do
    echo "Item: $item"  # Outputs each item as a string
done