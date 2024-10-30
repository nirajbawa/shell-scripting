#!/bin/bash

grep -i 'Unix' test3.txt

echo -e "\n\n"

grep -c 'linux' test3.txt

echo -e "\n\n"

grep -l 'linux' *