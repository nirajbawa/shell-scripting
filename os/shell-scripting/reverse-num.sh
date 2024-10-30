#!/bin/bash

<< comment
Write a shell script to print the given number in reverse order. (Make use of Make use of control flow statements and Make use of redirection operator and join commands to write the results in file)
Input-12345 Output-54321
comment

reverseNum()
{
    num=$1
    res=0
    # echo $1
    while [[ num -gt 0 ]];
    do
        rem=$(())
        res=$((res*10+(num%10)))
        num=$((num/10))
    done

    echo "reverse number is : $res"
    output="output.txt"
    {
        echo "entered number is : $1"
        echo "reverse number is : $res"
    } > "$output"
    echo "result is saved in file output.txt"
}

read -p "enter number : " num
reverseNum $num
