#!/bin/bash

awk '{ if($1 == $2) {print "hello"} else if ($1==$3) {print "hii"} else {print "Fail"} }' test4.txt

echo -e "\n\n"

awk '{ i=0; while(i<=NF){ print i ":" $i; i++;} }' test4.txt

echo -e "\n\n"

awk 'BEGIN { for(i=1; i<=10; i++) { print "The Square of ", i, "is", i*i; } }'

echo -e "\n\n"