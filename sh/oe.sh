#!/bin/bash
#oe / octopusengine

echo

if [[ $1 = "i" ]]; then
  echo "----- octopus engine info -----"
fi

x = 123 
price = 567

echo "whoami>" 
whoami
echo "pwd>" 
pwd
echo "free>"
free
echo "dp -h>"
df -h



if [[ $(which toilet) = "" ]]; then
                echo $price
        else
                toilet -t -f bigascii12 $price
        fi

echo $x
