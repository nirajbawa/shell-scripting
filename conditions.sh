#!/bin/bash

read -p "enter number : " number

if [[ $number%2 -eq 0 ]];
then
    echo "number is even"
else
    echo "number is not even"
fi

read -p "enter age : " age

if [[ age -le 10 ]];
then 
    echo "you are child"
elif [[ age -ge 11 && age -le 16 ]];
then
    echo "you are teenager"
else
    echo "you are adult"
fi