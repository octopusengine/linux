# linux<br />

simple "memory" AND SCRIPTS<br />
<hr />
man man<br />
man intro<br />
man -k = apropos STH<br />
uname -a<br />
w<br />
whoami -> @USER<br />
passwd<br />
sudo adduser newUser<br />
sudo passwd newUser<br />
hostname<br />
RPi: myPiName - /etc/hostname<br />
pwd -> DIR<br />
history | less / tail..<br />
alias COMM/expr. <br />
<i>alias hm="ls -l | wc -l"</i> (howmany)<br />
watch -n 30 COMM<br />
<i>grep alias ~/.bashrc</i><br />
man COMM (manual)<br />
COMM -h (help)<br />
dpkg -l | more (what is installed)<br />
<i>dpkg -l | grep -i game/python... (-i case intersensitive - Game / gaMe..)</i><br />
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
service ssh start<br />
/etc/init.d/ssh start<br />
ssh-copy-id<br />
<b>ssh IP</b> / ssh USER@IP<br />
<hr />
debug "Get picture from camera"<br />
fswebcam -r "${CAM_RESOLUTION}" --info "${CAM_INFO_TEXT}" --font "${CAM_FONT}" --banner-colour "${CAM_BANNER_COLOUR}" --text-colour<br /> ${CAM_TEXT_COLOUR} --line-colour ${CAM_LINE_COLOUR} /tmp/temp.jpg<br />
[ ! -e "/tmp/temp.jpg" ] && echo "Error while getting picture" >&2 && exit 1<br />
debug "Uploading photo to server"<br />
curl -s -X POST -F "fileToUpload=@/tmp/temp.jpg" -F "authkey=${UPLOAD_KEY}" -F "submit=1" ${UPLOAD_CURL_EXTRA_PARAMS} "${UPLOAD_URL}" > /dev/null
<hr />


cat FILE | less / more<br />
sudo nano FILE / vi<br />
cmp F1 F2<br />
hexdump -C FILE<br />
find <br />
sed (stream editor)<br />
nc (net cat / listen / connect)
sudo ifdown eth0 && sudo ifup eth0 (restart wifi)<br />
nohup (no hangup)<br />
<i>sudo nohup sh -c "ifdown eth0 && ifup eth0"</i><br />
ifconfig<br />
sudo route -n<br />
ping IP<br />
ping -c 5 google.com / 8.8.8.8<br />
ip a l / a s (addr show)<br />
nmap (network mapper)<br />
<b><i>nmap - sn / -v -A / -sP 192.168.0.*</i></b><br />
netstat -vat / -nr / -i / -ta<br />
<hr />
ps afux (process - all tree user)
ps afx | grep py > ID<br />
ps aux | grep -i vi (-i ignore case)<br />
kill ID<br />
kill $(ps aux | grep ´...´ | awk ...)<br />
sysv-rc-conf (start init)<br />
screen<br />
tmux / ctrl+B / Create Next Prew % (hor) " (vert)<br />
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
sudo apt-get update > upgrade<br />
reboot<br />

<hr />
<a href=http://wiki.ubuntu.cz/z%C3%A1kladn%C3%AD_p%C5%99%C3%ADkazy>wiky-ubuntu-cz</a><br />
<a href=http://searchdatacenter.techtarget.com/tutorial/77-Linux-commands-and-utilities-youll-actually-use>77-commands</a><br />
http://ifanda.cz/it/linux/2011-01-04-vicero-live-linuxu-na-jedne-usb-flash-klicence/
~~~
<hr />

<a href=http://www.root.cz/clanky/programovani-v-bash-shellu/>programovani-v-bash-shellu</a><br />
<a href=http://www.abclinuxu.cz/clanky/navody/bash-i>navody/bash-i</a><br />

