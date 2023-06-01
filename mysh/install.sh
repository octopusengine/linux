#!/bin/bash

# /home/user: cd
# mkdir mysh
# cd mysh
# wget https://raw.githubusercontent.com/octopusengine/linux/master/mysh/install.sh
# chmod +x inst20.sh
# ./install.sh

wget https://raw.githubusercontent.com/octopusengine/linux/master/mysh/info.sh
chmod +x info.sh
./info.sh

echo "============================================"
echo "--- yenda > install - octopus/agama 2017-23"
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
