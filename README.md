# linux

## simple notes & scripts

```bash
man man
man intro
man -k = apropos STH
uname -a
w
whoami -> @USER
passwd
sudo adduser newUser
sudo passwd newUser

hostname
RPi: myPiName - /etc/hostname
pwd -> DIR
history | less / tail..
history >> history123.txt

alias COMM/expr. 
alias hm="ls -l | wc -l"(howmany)
watch -n 30 COMM
grep alias ~/.bashrc
man COMM (manual)
COMM -h (help)
dpkg -l | more (what is installed)
dpkg -l | grep -i game/python... (-i case intersensitive - Game / gaMe..)

wc FILE
grep FILE
md5sum FILE
find DIR
wget http://abc.cz/sh/hi.sh
wget -O https://raw.githubusercontent.com/octopusengine/linux/master/ct/btc.sh

chmod 775 DIR(pwd)/hi.sh (change mode)
dmesg (report sit.)
free (mem)
sudo fdisk -l
sudo blkid
sudo mount -a / /media/usb1t
df / (space - disk free)
df -h (human)
du -sh /dir/
<du -s * | sort -nr > $HOME/user_space_report.txt
echo "& one more line" >> FILE / ~/name.txt
ls -lat (line all time)
ls -A (all)
mkdir
cp file.txt file-bak.txt
rm file.txt
echo file.txt byl > backup and delete


sudo apt-get install openssh-server
service ssh start
/etc/init.d/ssh start
ssh-copy-id
ssh IP / ssh USER@IP
debug "Get picture from camera"

fswebcam -r "${CAM_RESOLUTION}" --info "${CAM_INFO_TEXT}" --font "${CAM_FONT}" --banner-colour "${CAM_BANNER_COLOUR}" --text-colour<br /> ${CAM_TEXT_COLOUR} --line-colour ${CAM_LINE_COLOUR} /tmp/temp.jpg
[ ! -e "/tmp/temp.jpg" ] && echo "Error while getting picture" >&2 && exit 1

debug "Uploading photo to server"
curl -s -X POST -F "fileToUpload=@/tmp/temp.jpg" -F "authkey=${UPLOAD_KEY}" -F "submit=1" ${UPLOAD_CURL_EXTRA_PARAMS} "${UPLOAD_URL}" > /dev/null



cat FILE | less / more
sudo nano FILE / vi
cmp F1 F2
hexdump -C FILE
find
sed (stream editor)
nc (net cat / listen / connect)
sudo ifdown eth0 && sudo ifup eth0 (restart wifi)
nohup (no hangup)
sudo nohup sh -c "ifdown eth0 && ifup eth0"

ifconfig
sudo route -n
ping IP
ping -c 5 google.com / 8.8.8.8
ip a l / a s (addr show)
nmap (network mapper)
nmap - sn / -v -A / -sP 192.168.0.*
netstat -vat / -nr / -i / -ta


ps afux (process - all tree user)
ps afx | grep py > ID
ps aux | grep -i vi (-i ignore case)
kill ID
kill $(ps aux | grep ´...´ | awk ...)
sysv-rc-conf (start init)

screen
tmux / ctrl+B / Create Next Prew % (hor) " (vert)
htop
iotop
wiresharp-gtk
iftop
lsusb
lsmod
```

---

```bash
apt-get install python-pip
pip install pybitcoin


mc
shutdown -h / -r
sudo apt-get update > upgrade
reboot

system.d service:
https://www.linode.com/docs/quick-answers/linux/start-service-at-boot/
```

---

## links

<a href=http://wiki.ubuntu.cz/z%C3%A1kladn%C3%AD_p%C5%99%C3%ADkazy>wiky-ubuntu-cz</a><br />
<a href=http://searchdatacenter.techtarget.com/tutorial/77-Linux-commands-and-utilities-youll-actually-use>77-commands</a><br />
http://ifanda.cz/it/linux/2011-01-04-vicero-live-linuxu-na-jedne-usb-flash-klicence/
~~~
<hr />

<a href=http://www.root.cz/clanky/programovani-v-bash-shellu/>programovani-v-bash-shellu</a><br />
<a href=http://www.abclinuxu.cz/clanky/navody/bash-i>navody/bash-i</a><br />

