#!/bin/bash -x

echo "inst.sh > my install - octopusLab test 2017"
# sudo root ...
echo "-----basic--------------------------------"
apt install tmux htop tree iotop scrot neofetch
# lsusb lsmod 
echo "---network--------------------------------"
apt install net-tools nmap iftop
echo "---programs-------------------------------"
apt install gimp vlc cheese
echo "------------------------------------------"
 
