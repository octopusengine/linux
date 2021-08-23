#!/bin/bash

echo "============================================"
echo "-----  basic info  -------------------------"
echo "============================================"

w=$(whoami)
echo "- whoami   > " $w 
echo "- HOME     > " $HOME
echo "- HOSTNAME > " $HOSTNAME

echo "----- system info -------------------------"
uname -a
cat /proc/cpuinfo | grep "MHz" | sort -r | head -32

#free
echo "--- RAM - Memory Usage:"
/usr/bin/free -h

echo $'\n'$"--- HD - Disk Usage:"
/bin/df -h /dev/sd[a-z][1-9] 2>/dev/null
disk=$(du -sh)
echo "--> " $disk 

echo $'\n'$"--- Uptime:"
/usr/bin/uptime

echo "--- NETw ---"
ifconfig | grep broadcast


echo "============================================"
echo "--- instYY.sh > install - octopusLab 2017-20"
echo "============================================"
# sudo root ...


echo "-----basic--------------------------------"
apt install tmux htop tree iotop scrot
apt install cmatrix cowsay toilet


echo "-----system--------------------------------"
sudo add-apt-repository universe # todo: IF for Ubuntu
sudo apt install mc
apt install lsusb lsmod    
apt install gparted    # partitions
apt install lm-sensors # sensors


echo "---network--------------------------------"
apt install net-tools nmap iftop


echo "---programs-------------------------------"
apt install gimp vlc cheese


echo "------------------------------------------"
apt install neofetch

wget https://github.com/dylanaraps/pfetch/archive/master.zip
unzip master.zip
sudo install pfetch-master/pfetch /usr/local/bin/

ls -l /usr/local/bin/pfetch
echo $'\n'$"./pfetch"

exit
