#!/bin/bash 

#chmod 775 $HOME/mysh/info.sh
# run:
# $HOME/mysh/info.sh

python3 $HOME/mysh/octopus.py

echo "info.sh > octopusLab info 2017-2020"
echo "---basic--------------------------------"
w=$(whoami)
echo "- whoami > " $w 
echo "- HOME   > " $HOME


echo "---system---"
uname -a
cat /proc/cpuinfo | grep "MHz" | sort -r | head -32
disk=$(du -sh)
echo "- disk usage > " $disk 

echo "---RAM---"
free


echo "---NETw---"
ifconfig | grep broadcast
echo "----------------------------------------"
 
