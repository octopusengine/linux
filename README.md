# linux<br />

simple "memory" AND SCRIPTS<br />
<hr />
uname -a<br />
whoami -> @USER<br />
passwd<br />
sudo adduser newUser<br />
sudo passwd newUser<br />
RPi: myPiName - /etc/hostname<br />
pwd -> DIR<br />
history | less / tail..<br />
alias COMM/expr.<br />
watch -n 30 COMM<br />
<i>grep alias ~/.bashrc</i><br />
man COMM (manual)<br />
COMM -h (help)<br />
dpkg -l | more (what is installed)<br />
<i>dpkg -l | grep -i game (-i case intersensitive - Game / gaMe..)</i><br />
wc FILE<br />
grep FILE<br />
md5sum FILE<br />
find DIR<br />
wget http://abc.cz/sh/hi.sh<br />
wget -O https://raw.githubusercontent.com/octopusengine/linux/master/ct/btc.sh<br />
chmod 775 DIR(pwd)/hi.sh (change mode)<br />
dmesg (report sit.)<br />
free (mem)<br />
sudo fdisk -l<br />
sudo blkid<br />
sudo mount -a / /media/usb1t<br />
df / (space - disk free)<br />
df -h (human)<br />
du -sh /dir/<br />
<b>du -s * | sort -nr > $HOME/user_space_report.txt</b><br />
echo "& one more line" >> FILE / ~/name.txt<br />
ls -lat (line all time)<br />
ls -A (all)<br />
mkdir<br />
cp file.txt file-bak.txt<br />
rm file.txt<br />
echo file.txt byl > backup and delete<br />
sudo apt-get install openssh-server<br />
service ssh strat<br />
/etc/init.d/ssh start<br />
ssh-copy-id<br />
<hr />
cat FILE | less / more<br />
sudo nano FILE / vi<br />
cmp F1 F2<br />
find <br />
sed (stream editor)<br />
nc (net cat / listen / connect)
sudo ifdown eth0 && sudo ifup eth0 (restart wifi)<br />
nohup (no hangup)<br />
<i>sudo nohup sh -c "ifdown eth0 && ifup eth0"</i><br />
ifconfig<br />
sudo route -n<br />
ping IP<br />
ping -c 5 google.com / 8.8.8.8
ip a l / a s (addr show)<br />
nmap (network mapper)<br />
<b><i>nmap - sn / -v -A / -sP 192.168.0.*</i></b><br />
netstat -vat / -nr / -i / -ta<br />
<hr />
ps afux (process - all tree user)
ps afx | grep py > ID<br />
ps aux | grep -i vi (-i ignore case)<br />
kill ID<br />
kill $(ps aux | grep ´...´ | awk ...)
sysv-rc-conf (start init)<br />
screen<br />
tmux / alt+B / Create Next Prew % (hor) " (vert)<br />
htop<br />
iotop<br />
wiresharp-gtk<br />
iftop<br />
lsusb<br />
lsmod<br />
<hr />
apt-get install python-pip<br />
pip install pybitcoin<br / >
<hr />
mc<br />
shutdown -h / -r<br />
reboot<br />

<hr />
<a href=http://wiki.ubuntu.cz/z%C3%A1kladn%C3%AD_p%C5%99%C3%ADkazy>wiky-ubuntu-cz</a><br />
<a href=http://searchdatacenter.techtarget.com/tutorial/77-Linux-commands-and-utilities-youll-actually-use>77-commands</a><br />
~~~
<hr />

<a href=http://www.root.cz/clanky/programovani-v-bash-shellu/>programovani-v-bash-shellu</a><br />
<a href=http://www.abclinuxu.cz/clanky/navody/bash-i>navody/bash-i</a><br />

