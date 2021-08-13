# linux

## The Most Useful Linux Commands To Run in the Terminal

### Basic
```bash
man man
man COMM (manual) man intro
man -k = apropos STH
which bash / APP
history | less / tail..  (CTRL+R)
history >> history123.txt
alias COMM/expr. ("rename")
alias hm="ls -l | wc -l" (hm = howmany)
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
clear      (clear terminal / CTRL+L)
tput civis (cursor off)
tput cnorm (cursor on)
```

### Hardware & System
```bash
lscpu           (cpu architecture)
uname -a        (display Linux system info) - r (kernel release)
last reboot     (reboot history)
date            (current date and time)
cal             (month calendar)
lsblk           (block device related info)
blkid           (nlock device atributes)
mount
free (mem)
sudo fdisk -l
sudo mount -a / /media/usb1t
less /etc/fstab
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
chmod +x FILE ("executable" - better)
chown owner-user FILE

sudo su - (as a superuser)
su - USER (as e user)
exit
```

### String / File commands
```bash
pwd -> DIR      (Print Work Directory - path of current dir)
ls -lat         (list - line all time)
ls -A           (- all)
cd
cd ~/.. && cd /var/www/...
pushd
popd
mkdir
rmdir
touch FILE              (create or update F)
cat > FILE              (write and create..)  end: CTRL+C / D
cat >> FILE             (add..)
cat F1 F2 > F3 (join)
echo "add line" >> FILE
sudo nano FILE / vi / gedit

cp F1 F2                (copy source destination) cp file.txt file-bak.txt
mv F1 F2                (move)
cmp F1 F2               (compare)
rm file.txt
echo file.txt byl > backup and delete
cat FILE | less / more
awk '{print}' FILE = cat FILE
awk '{print $2}' / col.
awk -F':' '{print $1,$7}' /etc/password (-F: separator)
hexdump -C FILE
tr              (translate or delete characters)
echo test | tr -d"t" >> es
echo -n "agama3" | sha256sum | tr -d "[:space:]-" >> correct hash
find
wc FILE
grep FILE/EXPR  (history: g/re/p - print regul.expr.)
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

### Process / System
```bash
ps afux (process - all tree user)
ps afx | grep py > ID
ps aux | grep -i vi (-i ignore case)
kill ID / NAME
kill $(ps aux | grep ´...´ | awk ...)
killall
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

system nginx status / start / stop / restart
systemctl status nginx
systemctl daemon-reload

ls /etc/systemd/system
```

### Network
```bash
hostname
RPi: myPiName - /etc/hostname
ifconfig
alias ipaddress="ifconfig | grep broadcast | awk `{print $2}`" 
alias ipaddress="echo $(ifconfig | grep broadcast | awk `{print $2}`)" 
ethtool eth()
ip addr
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
netstat -vat / -nr / -i / -ta (install net-tools)
netstat -tulpn  (ports)
bsh-write       (send message)

ssh
sudo apt-get install openssh-server
service ssh start
/etc/init.d/ssh start
ssh-copy-id
ssh IP / ssh USER@IP

scp USER@IP_ADDR:/home/USER/FILE.src FILE.dest  (netw copy)

sftp IP  (secure FTP) 
> ls/lls / pwd/lpwd / cd/lcd
> get FILE / -r DIR
> put FILE
> bye

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

### Aps & Etc. (terminal)
```bash
tmux / ctrl+B / Create: % (-) " (|) ! (x) Next Prew >
mc (norton comm.)
scrot (print screen)
neofetch (system info)
toilet -f mono12 -F metal Tecmint.com
figlet Welcome
asciiview elephant.jpg -driver curses 
echo "octopusengine[dot]com is a community of Linux Nerds and Geeks" | pv -qL 10  (x ./baudprint.pl 600)
rig (random identity)
sl (Steam Locomotive)
asciiquarium
cowsay Hello
cowsay -f ghostbusters Who you Gonna Call
cowthink ...funny
telnet towel.blinkenlights.nl
curl -u YourUsername:YourPassword -d status="message" http://twitter.com/statuses/update.xml

bc (line calculator)
echo "12+5" | bc
hex="FF" && echo "obase=10;ibase=16;$hex" | bc  ( -> 255 )
echo "1==2" | bc           ( -> 0 )
echo "10>5" | bc           ( -> 1 )
pi=`echo "h=10;4*a(1)" | bc -l`    ( echo $pi -> 3.14...)

```

---

### bash / CPP / Python
```bash
#!bin/sh x #!bin/bash
$BASH (/usr/bin/bash) $SHELL (/bin/bash)
$HOME (/home/$USER) ($USER/$HOSTNAME $HOSTTYPE) $PATH
$EDITOR $BROWSER
$LANG (en_US.UTF-8) $LINES (58)

apt-get install python-pip
pip install pybitcoin

cd python-proj-dir
python3 -m venv venv  (virtual environment)
source ./venv/bin/activate
```
---

## games
```
/usr/games

./rogue

```

## SW / APP  (x-prg)
```
thunar (file manager)
brave  (web browser + tor) 

```





## links

https://ss64.com/bash/

<a href=http://wiki.ubuntu.cz/z%C3%A1kladn%C3%AD_p%C5%99%C3%ADkazy>wiky-ubuntu-cz</a><br />
<a href=https://www.ubuntupit.com/best-linux-commands-to-run-in-the-terminal/>50 best-linux-commands</a><br />
<a href=http://searchdatacenter.techtarget.com/tutorial/77-Linux-commands-and-utilities-youll-actually-use>77-commands</a><br />
http://ifanda.cz/it/linux/2011-01-04-vicero-live-linuxu-na-jedne-usb-flash-klicence/<br />
system.d service: https://www.linode.com/docs/quick-answers/linux/start-service-at-boot/<br />
https://linuxconfig.org/bash-scripting-tutorial<br />
https://github.com/LukeSmithxyz/shortcut-sync<br />
https://github.com/EzeeLinux/ezeelinux-script-collection<br />

<hr />

<a href=http://www.root.cz/clanky/programovani-v-bash-shellu/>programovani-v-bash-shellu</a><br />
<a href=http://www.abclinuxu.cz/clanky/navody/bash-i>navody/bash-i</a><br />
<a href=https://edu.dtlab.cz/linux/>edu.dtlab.cz/linux</a><br />
