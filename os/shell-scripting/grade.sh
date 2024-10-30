#!/bin/bash

# Write a shell script to calculate a student's grade based on marks entered for three subjects. 
# The script should prompt the user for the marks of each subject, calculate the total and 
# percentage, and then assign a grade based on the percentage: 
# = 90: Grade A 
# =75: Grade B 
# = 50: Grade C 
# < 50: Fail 
# (Make use of Make use of control flow statements and Make use of redirection operator and 
# join commands to write the results in file)


read -p "enter marks of subject 1 : " sub1
read -p "enter marks of subject 2 : " sub2
read -p "enter marks of subject 3 : " sub3

if [[ sub1 -lt 0 || sub1 -gt 100 ]];
then 
    echo "marks must be range between the 0 to 100"
fi

if [[ sub2 -lt 0 || sub2 -gt 100 ]];
then 
    echo "marks must be range between the 0 to 100"
fi

if [[ sub3 -lt 0 || sub3 -gt 100 ]];
then 
    echo "marks must be range between the 0 to 100"
fi

total=$((sub1+sub2+sub3))

per=$(echo "scale=2; ($total / 300) * 100" | bc)

echo -e "\nyour percentage is : $per \n\n"

if (( $(echo "$per >= 90" | bc -l) ))
then    
    echo "your grade is A"
elif (( $(echo "$per >= 75" | bc -l) ));
then
    echo "your grade is B"
elif (( $(echo "$per >= 50" | bc -l) ));
then 
    echo "your grade is C"
else
    echo "your grade is Fail"
fi