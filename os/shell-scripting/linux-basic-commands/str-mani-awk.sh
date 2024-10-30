#!/bin/bash

# Print the lines which match the given pattern
awk '/niraj/{print}' test5.txt

echo -e "\n\n"

# Splitting a Line Into Fields
awk '{print $1,$2}' test5.txt

echo -e "\n\n"

# To find the length of the longest line present in the file
awk '{ if (length($0) > max) { max=length($0)  }} END {print max} ' test5.txt

echo -e "\n\n"

# Printing the lines with more than specified characters
awk 'length($0) > 10' test5.txt

echo -e "\n\n"

awk '{ if(length($0) > 10) {print $0} }' test5.txt

echo -e "\n\n"