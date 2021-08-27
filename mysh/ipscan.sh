#!/bin/bash

# $ ./ipscan.sh 192.168.0 > iplist.txt
# $ for ip in $(cat iplist.txt); do nmap -sS -p 80 -T4 $ip & done
# --------------------------------------------------------


if [ "$1" == "" ]
then

echo "You forgot a parameter (IP address)"
echo "Example: ./ipscan.sh 192.168.0"

else
for ip in $(seq 1 254)
do
ping -c 1 $1.$ip | grep "64 bytes" | cut -d " " -f 4 | tr -d ":" &
done

fi
