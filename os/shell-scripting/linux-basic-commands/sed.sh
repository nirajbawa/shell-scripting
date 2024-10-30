#!/bin/bash

sed 's/linux/unix/' test3.txt

echo -e "\n\n"

sed 's/linux/unix/2' test3.txt

echo -e "\n\n"

sed '1d' test3.txt

echo -e "\n\n"

sed '1,2d' test3.txt

echo -e "\n\n"

sed '/linux/d' test3.txt

echo -e "\n\n"