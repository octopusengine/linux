#!/bin/sh
#http://www.root.cz/clanky/programovani-v-bash-shellu/
arg1=$1
echo "NumArg>" $#
echo "Arg1" $arg1

echo "cd>"
#cd ..
cd my-python
echo "lcd>"
sudo python _dispi2c.py internet_radio: JamJazz
ech "audio>"
amixer cset numid=3 1

mpc playlist
echo "play>"
if [ "$#" -eq 1 ]; then 
  mpc play $arg1
else
 mpc play 1   
fi

sleep 2s
echo "current>"
mpc current
song = mpc current

exit 0