# linux

[Directory structure](https://github.com/octopusengine/linux/blob/master/directory_struct.md)

[Applications and Programs](https://github.com/octopusengine/linux/blob/master/app_prg.md)

[Links](https://github.com/octopusengine/linux/blob/master/links.md)

---

## The Most Useful Linux Commands To Run in the Terminal


### Basic
```bash
man man
man COMM (manual) man intro
man -k = apropos STH
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

$PATH
which bash / APP (ls > /usr/bin/ls) 
whereis APP (ls > ls: /usr/bin/ls /usr/share/man/man1/ls.1.gz)
```

### Sources

https://www.gnu.org/software/coreutils/manual/html_node/ls-invocation.html#ls-invocation

https://github.com/wertarbyte/coreutils/blob/master/src/ls.c


### Hardware & System
```bash
sudo apt-get update && apt-get upgrade
lscpu           (cpu architecture)
uname -a        (display Linux system info) - r (kernel release)
last reboot     (reboot history)
date            (current date and time)
cal             (month calendar)
blkid           (nlock device atributes)
lsblk           (block device related info)
mount DEV PATH  / sudo mount /dev/sdb1 usb-disk
free (mem)
sudo fdisk -l
sudo mount -a / /media/usb1t
less /etc/fstab
df / (space - disk free)
df -h (human)
du -sh /dir/
<du -s * | sort -nr > $HOME/user_space_report.txt
screen

temporary RAMdisk:
mknod -m 660 /dev/ram b 1 1
chown root:disk /dev/ram
```

### Users & file permission related
```bash
w               (who is online)
who
whoami -> @USER (who you are logged as)
id              (Print user and group id's)
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
~ $ >           (~ home directory, $ home user)
cd PATH         (change directory)
cd; cd /; cd ~  (/home/USER; / "root"; = cd > home/USER) 
ls -lat         (list - line all time) (l=list, a=all, t=time/default Abc)
ls -d */        (only sub/DIR)
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
locate STR 
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
cron                  (Daemon to execute scheduled commands)
crontab               (Schedule a command to run at a later time)
lsusb
lsmod
shutdown -h / -r      (Shutdown or restart linux)
reboot                (Reboot the system)

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
ifconfig | grep broadcast | awk '{print $2}'   (get IP)
hostname -I                                    (get IP)
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
dig domain      (DNS lookup)
dig -x host     (reverse lookup)
traceroute      (Trace Route to Host)
mtr             (Network diagnostics - traceroute/ping)
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
logout

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
