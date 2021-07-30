# linux

## The Most Useful Linux Commands To Run in the Terminal

### Basic

```bash
man man
man COMM (manual) man intro
man -k = apropos STH
which bash
awk
history | less / tail..
history >> history123.txt
alias COMM/expr. ("rename")
alias hm="ls -l | wc -l"(howmany)
sleep 2 (pause 2 sec)
watch -n 30 COMM (periodic)
grep alias ~/.bashrc
COMM -h (help)
apt install / remove / APPLICATION
sudo locate APPLICATION
sudo apt-get purge APPLICATION
dpkg -l | more (what is installed)
dpkg -l | grep -i game/python... (-i case intersensitive - Game / gaMe..)
sudo dpkg --configure -a
ps -ef | grep dpkg*  --> kill PID# 
```

### Hardware & System
```bash
lscpu           (cpu architecture)
uname -a        (display Linux system info) - r (kernel release)
last reboot     (reboot history)
date            (current date and time)
cal             (month calendar)
lsblk           (block device related info)
mount
free (mem)
sudo fdisk -l
sudo mount -a / /media/usb1t
df / (space - disk free)
df -h (human)
du -sh /dir/
<du -s * | sort -nr > $HOME/user_space_report.txt
screen
```

### Users & file permission related
```bash
w               (who is online)
who
whoami -> @USER (who you are logged as)
uptime
finger user     (info about user)
sudo adduser newUser
sudo passwd newUser
passwd
chmod           (change the permission of file to octal)
chmod 775 DIR (pwd)/hi.sh ( - change mode to 775)
chown owner-user FILE 
```

### File commands
```bash
pwd -> DIR      (Print Work Directory - path of current dir)
ls -lat         (list - line all time)
ls -A           (- all)
cd
cd ~/.. && cd /var/www/...
mkdir
rmdir
touch FILE      (create or update F)
cp F1 F2        (copy) cp file.txt file-bak.txt
mv F1 F2        (move)
cmp F1 F2       (compare)
rm file.txt
echo file.txt byl > backup and delete
cat FILE | less / more
sudo nano FILE / vi
hexdump -C FILE
find
wc FILE
grep FILE/EXPR
md5sum FILE
gpg -c FILE     (encrypt F)
gpg file.gpg    (decrypt F)
find DIR/FILE
wget URL
wget -O https://raw.githubusercontent.com/octopusengine/linux/master/ct/btc.sh
scp             (file transfer)
dmesg (report sit.)
sudo blkid
echo "& one more line" >> FILE / ~/name.txt
sed (stream editor)

```

### Process
```bash
ps afux (process - all tree user)
ps afx | grep py > ID
ps aux | grep -i vi (-i ignore case)
kill ID
kill $(ps aux | grep ´...´ | awk ...)
sysv-rc-conf (start init)
tail -f /var/log/uwsgi/app/*.log
service
htop (better top)
iotop
wiresharp-gtk
lsusb
lsmod
shutdown -h / -r
sudo apt-get update > upgrade
reboot
```

### Network
```bash
hostname
RPi: myPiName - /etc/hostname
ifconfig
alias ipaddress="ifconfig | grep broadcast | awk `{print $2}`" 
alias ipaddress="echo $(ifconfig | grep broadcast | awk `{print $2}`)" 
ethtool eth()
curl [options] URL -- dtata transfer (HTTP, FTP, IMAP, POP3, SCP, SFTP, SMTP, TFTP, TELNET, LDAP or FILE)
nc (net cat / listen / connect)
iftop
sudo route -n
ping host-IP
ping -c 5 google.com / 8.8.8.8
whois domain
dig domain      (get DNS info)
dig -x host     (reverse lookup)
ip a l / a s    (addr show)
nmap (network mapper)
nmap - sn / -v -A / -sP 192.168.0.*
nmap - sT -p80,433 192.168.0.* | grep report (scan TCP-IP for port)
netstat -vat / -nr / -i / -ta
bsh-write       (send message)

ssh
sudo apt-get install openssh-server
service ssh start
/etc/init.d/ssh start
ssh-copy-id
ssh IP / ssh USER@IP

scp USER@IP_ADDR:/home/USER/FILE.src FILE.dest (netw copy)
python3 -m http.server
>> browser: http://IP_ADDR:8000/

```

### webcam
```bash
cheese

fswebcam -r "${CAM_RESOLUTION}" --info "${CAM_INFO_TEXT}" --font "${CAM_FONT}" --banner-colour "${CAM_BANNER_COLOUR}" --text-colour<br /> ${CAM_TEXT_COLOUR} --line-colour ${CAM_LINE_COLOUR} /tmp/temp.jpg
debug "Get picture from camera"
[ ! -e "/tmp/temp.jpg" ] && echo "Error while getting picture" >&2 && exit 1
debug "Uploading photo to server"
curl -s -X POST -F "fileToUpload=@/tmp/temp.jpg" -F "authkey=${UPLOAD_KEY}" -F "submit=1" ${UPLOAD_CURL_EXTRA_PARAMS} "${UPLOAD_URL}" > /dev/null
```

```
sudo ifdown eth0 && sudo ifup eth0 (restart wifi)
nohup (no hangup)
sudo nohup sh -c "ifdown eth0 && ifup eth0"
```

### Aps & Etc.
```bash
tmux / ctrl+B / Create: % (-) " (|) ! (x) Next Prew >
mc (norton comm.)
scrot (print screen)
neofetch (system info)
toilet -f mono12 -F metal Tecmint.com
figlet Welcome
asciiview elephant.jpg -driver curses 
echo "octopusengine[dot]com is a community of Linux Nerds and Geeks" | pv -qL 10
rig (random identity)
sl (Steam Locomotive)
asciiquarium
cowsay Hello
cowsay -f ghostbusters Who you Gonna Call
cowthink ...funny
telnet towel.blinkenlights.nl
curl -u YourUsername:YourPassword -d status="message" http://twitter.com/statuses/update.xml
```

---

### bash / CPP / Python
```bash
#!bin/sh x #!bin/bash
$BASH (/usr/bin/bash) $SHELL (/bin/bash)
$HOME (/home/$USER) $HOSTNAME $HOSTTYPE
$EDITOR $BROWSER
$LANG (en_US.UTF-8) $LINES (58)


apt-get install python-pip
pip install pybitcoin

python3 -m venv venv
source ./venv/bin/activate


```
---

## links

<a href=http://wiki.ubuntu.cz/z%C3%A1kladn%C3%AD_p%C5%99%C3%ADkazy>wiky-ubuntu-cz</a><br />
<a href=https://www.ubuntupit.com/best-linux-commands-to-run-in-the-terminal/>50 best-linux-commands</a><br />
<a href=http://searchdatacenter.techtarget.com/tutorial/77-Linux-commands-and-utilities-youll-actually-use>77-commands</a><br />
http://ifanda.cz/it/linux/2011-01-04-vicero-live-linuxu-na-jedne-usb-flash-klicence/<br />
system.d service: https://www.linode.com/docs/quick-answers/linux/start-service-at-boot/<br />
https://linuxconfig.org/bash-scripting-tutorial<br />
https://github.com/LukeSmithxyz/shortcut-sync<br />

<hr />

<a href=http://www.root.cz/clanky/programovani-v-bash-shellu/>programovani-v-bash-shellu</a><br />
<a href=http://www.abclinuxu.cz/clanky/navody/bash-i>navody/bash-i</a><br />
<a href=https://edu.dtlab.cz/linux/>edu.dtlab.cz/linux</a><br />
