#!/bin/bash

<< comment
Write a shell seript to find factorial of a given number and find whether the given number is 
prime or not. (Make use of control flow statements and Make use of redirection operator and 
join commands to write the results in file)
comment

read -p "enter number : " num

res=1;

for (( i=1; i<=num; i++ ))
do
    res=$((res*i));
done 

echo "factorial is : $res"

output="output.txt"
{
    echo "entered number is : $num"
    echo "factorial is : $res"
} >> "$output"

{
    isPrime=1

    if [[ $num -eq 1 ]];
    then
        isPrime=0
    fi

    for ((i=2; i<num; i++));
    do  
        if [[ $((num%i)) == 0 ]];
        then
            isPrime=0
            break
        fi
    done

    if [[ $isPrime -eq 1 ]];
    then
        echo "number is prime"
    else
        echo "number is not prime"
    fi
} >> "$output"

echo "output is saved into file"
