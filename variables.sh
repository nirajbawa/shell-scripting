#!/bin/bash

#this is comment

<< comment
this is multiline comment
comment

name="niraj"

echo "hello $name"
echo "date : $(date)"

read -p "Enter username : " username

echo "username : $username"

cat /etc/passwd


# sudo userdel -r nirajbava
# sudo useradd nirajbava

i="1"

res=$(expr "$i" + 10)
echo "Result : $res"

i="1.5"
res=$(echo "$i" + 10 | bc)
echo "Result : $res"