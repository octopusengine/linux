#!/bin/bash 

#chmod 775 $HOME/mysh/info.sh
# run:
# $HOME/mysh/info.sh

echo "oi.sh > octopusLab info 2017-2020"
echo "---basic--------------------------------"
echo "---system---"
uname -a
cat /proc/cpuinfo | grep "MHz" | sort -r | head -32
echo "---disk---"
du -sh
#disk=`du -sh`
#echo "disk > `$disk`" 
echo "---RAM---"
free
w=whoami
echo "whoami > `$w`" 
echo "---NETw---"
ifconfig | grep broadcast
echo "----------------------------------------"
 
