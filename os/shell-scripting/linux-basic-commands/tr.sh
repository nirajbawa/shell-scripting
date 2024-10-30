#!/bin/bash

output="niraj Bava"

echo -e "lower case to upper \n"
echo $output | tr [a-z] [A-Z]

echo -e "\nupper case to lower \n"
echo $output | tr [A-Z] [a-z]


output="good  night  {}"
echo -e "\nstring replacing : \n"
echo $output | tr "{}" "()"


echo -e "\nremove all repeatative characters\n"
echo "welcome  to  linux" | tr -s " "

echo -e "\ndelete specified characters\n"
echo "welcome  to  linux" | tr -d "w" 

echo -e "\ncomplement specified characters\n"
echo "welcome to linux 12345" | tr -cd [:digit:]

echo -e "\n\n"