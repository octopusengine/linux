#!/bin/bash

# add script to /home/USER/.bashrc

now="`date +%y-%m-%d/%H:%M`"
echo $now $USER >> $HOME/mylog/loglist.txt

exit

