#!/bin/bash

<< comment

Write a shell script for following: 
Read first 25 numbers from user 
Print first five even numbers 
Print first five odd numbers 
Print first prime numbers 
(Make use of redirection operator and join commands to write the results in file)

comment


output="output.txt"
>"$output"

echo "Enter 25 numbers:"
read -a numbers  

if [[ ${#numbers[@]} -ne 25 ]];
then   
    echo "please enter 25 numbers exactly"
    exit 1
fi


{
count=0
echo -e "\n\nPrint first five even numbers :"

for num in "${numbers[@]}";
do
    if [[ $((num%2)) -eq 0 ]];
    then 
        echo " $num "
        ((count++))
    fi
    if [[ $count -eq 5 ]];
    then  
        break
    fi
done

} >> "$output"


{
count=0
echo -e "\n\nPrint first five odd numbers :"
for num in "${numbers[@]}";
do
    if [[ $((num%2)) -ne 0 ]];
    then 
        echo " $num "
        ((count++))
    fi
    if [[ $count -eq 5 ]];
    then  
        break
    fi
done
} >> "$output"
    


{
    count=0
    echo -e "\n\nPrint first prime numbers : "
    for num in "${numbers[@]}";
    do
        isPrime=1

        if [[ $num -lt 2 ]];
        then 
            isPrime=0
        else
            for ((i=2; i<num; i++));
            do  
                if [[ $((num%i)) -eq 0 ]];
                then 
                    isPrime=0
                    break
                fi
            done
        fi
        

        if [[ isPrime -eq 1 ]];
        then 
            echo " $num "
            ((count++))
        fi

        if [[ $count -eq 5 ]];
        then  
            break
        fi
    done
        
} >> "$output"