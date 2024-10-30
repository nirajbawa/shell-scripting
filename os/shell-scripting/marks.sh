#!/bin/bash

# Write a shell script which reads 5 subjects marks. Calculate total, average and find the final 
# class obtained by the students. (Make use of control flOw stateiments and switch case 
# statement)

echo "enter subjects marks : "
read -a marks

if [[ ${#marks[@]} -ne 5 ]];
then 
    echo "enter exactly 5 subject marks"
    exit 1
fi

total=0

for sub in "${marks[@]}";
do
    total=$((total+sub))
done

average=$((total/5))

echo "your total marks are $total"
echo "your average marks are $average"

case $average in
    8[0-9] | 9[0-9] | 100)
        echo "your grade is A"
        ;;
     7[0-9])
        echo "your grade is B"
        ;;
    5[0-9] | 6[0-9])
        echo "your grade is C"
        ;;
    *)
        echo "your are Fail"
esac
