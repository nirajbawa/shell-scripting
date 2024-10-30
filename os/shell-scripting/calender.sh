#!/bin/bash

# Write a shell script that prompts the user to input a specific year and month, and then 
# displays the corresponding calendar for that month and year. The script should ensure that the 
# user enters a valid month (between l and 12), If an invalid month is entered, the script should 
# display an error message and terminate the program. Use the cal command to display the 
# calendar.

read -p "enter month : " month

if [[ $month -lt 1 || $month -gt 12 ]];
then 
    echo "please enter valid month"
    exit 1
fi

read -p "enter year : " year

if [[ $year -lt 1 || $year -gt 9999 ]];
then 
    echo "year must be in range of 1..9999"
    exit 1
fi

echo -e "\n\n"

cal $month $year