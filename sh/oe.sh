#!/bin/bash
#oe / octopusengine
#wget https://raw.githubusercontent.com/octopusengine/linux/master/sh/oe.sh
#chmod 755 ../oe.sh

echo
if [[ $1 = "i" ]]; then
  echo "----- octopus engine info -----"
  uname -a
  w=whoami
  echo "whoami > $w" 
  d=pwd
  echo "pwd > $d"  
fi

x=123 
price=567



if [[ $2 = "m" ]]; then
  echo "----- memory RAM..HD -----"
  echo "free>"
  free
  echo "dp -h>"
  df -h
fi

#if [[ $(which toilet) = "" ]]; then
#                echo $price
#        else
toilet -t -f bigascii12 $price
#fi
#echo $x
