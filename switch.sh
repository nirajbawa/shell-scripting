#!/bin/bash

read -p "select option : " num

case $num in 
    1)
        echo "selected option is one";;
    2)
        echo "selected option is two";;
    *)
        echo "selected option not exist"
esac