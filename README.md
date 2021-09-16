# linux

[Directory structure](https://github.com/octopusengine/linux/blob/master/directory_struct.md)

[Applications and Programs](https://github.com/octopusengine/linux/blob/master/app_prg.md)

[Disk](https://github.com/octopusengine/linux/blob/master/disk.md)

[Network](https://github.com/octopusengine/linux/blob/master/network.md)

[Links](https://github.com/octopusengine/linux/blob/master/links.md)

---

## The Most Useful Linux Commands To Run in the Terminal

```bash
$ = another example (~ example describe)
$ -> return
/ = or
COMM = command
COMM -> RESULT  (by executing the command we get the result)
USER
FILE
DIR
IP
...
```

### Basic
```bash
type COMM                  (find out the information about a Linux command)
help COMM
COMM -h / --help           (help)
man COMM                   (manual page)
$ man man / $ man intro    
$ man -k = apropos STH     (where is man...)
tldr COMM                  (“Too Long - Didn’t Read“. Pages are summarized practical usage examples of commands..)

COMM1 ; COMM2              (1 then 2)
$ date +%T; sleep 5; date +%T
COMM1 & COMM2 &            (1 and 2)
$ date & sleep & date
& yes comm1 & yes comm2    ( -> comm1 2122121212121112111...) 
COMM1 && COMM2             (if 1 then 2)
z

history                    (Command History - CTRL+R)
$ history | less / tail..   
$ history >> history123.txt
alias COMM/expr. ("rename")
$ alias hm="ls -l | wc -l" (hm = howmany)
sleep 2                    (Delay for a specified time - 2 sec)
watch -n 30 COMM           (Execute/display a program periodically)
grep alias ~/.bashrc
$ apt install / remove / APPLICATION
$ sudo locate APPLICATION
$ sudo apt-get purge APPLICATION
dpkg                      (Package manager - Debian/Ubuntu)
$ dpkg -l | more          (~ what is installed)
$ dpkg -l | grep -i game/python... (-i case intersensitive - Game / gaMe..)
$ sudo dpkg --configure -a
rpm                       (RedHat Package Manager)

clear                     (clear terminal / CTRL+L)
tput civis                (cursor off)
tput cnorm                (cursor on)

$PATH
which bash / APP          (ls > /usr/bin/ls) 
whereis APP               (ls > ls: /usr/bin/ls /usr/share/man/man1/ls.1.gz)

st            (simple terminal - install sttrminal)
```

### Sources

https://www.gnu.org/software/coreutils/manual/html_node/ls-invocation.html#ls-invocation

https://github.com/wertarbyte/coreutils/blob/master/src/ls.c


### Hardware & System
```bash
sudo apt-get update && apt-get upgrade
lscpu                  (cpu architecture)
$ cat /proc/cpuinfo
$ cat /proc/meminfo
vmstat                 (Report virtual memory statistics)
$ vmstat -S M
iostat                 (Report CPU and i/o statistics)
$ iostat -mdz / ? -wmdz
mpstat                 (Report processor related statistics)

uname -a               (display Linux system info) - r (kernel release)
last reboot            (reboot history)
date                   (current date and time)
cal                    (month calendar)
free                   (memory)
$ free -h | awk '/^Mem:/ {print $3 "/" $2}'        (Memory used: used/total)
screen

env                    (Environment variables)
set                    (Manipulate shell variables and functions)

```

[Disk](https://github.com/octopusengine/linux/blob/master/disk.md)



### Users & file permission related
```bash
w                       (who is online)
who
whoami -> @USER         (who you are logged as)
id                      (Print user and group id's)
uptime
finger user             (info about user)
sudo adduser newUser
sudo passwd newUser
passwd
$ echo abc123 | cracklib-check   
$ -> it is too simplistic/systematic

chmod                   (change the permission of file to octal)
$ chmod 775 DIR         (~ pwd)/hi.sh ( - change mode to 775)
$ chmod +x FILE         (~ "executable" - better)
chown owner-user FILE

sudo su - (as a superuser)
su - USER (as e user)
exit
```

### String / File commands
```bash
pwd -> DIR              (Print Work Directory - path of current dir)
~ $ >                   (~ home directory, $ home user)
cd PATH                 (change directory)
cd; cd /; cd ~          (/home/USER; / "root"; = cd > home/USER) 
ls                      (List information about file/s)
$ ls -lat               (~ list - line all time) (l=list, a=all, t=time/default Abc)
$ ls -i                 (inode)
$ stat FILE             (info)
$ ls -d */              (~ only sub/DIR)
$ alias ls="ls --color=auto"
$ alias ll="ls -alF"    (... for bashrs)
pushd                   (Save and then change the current directory)
popd                    (Restore the previous value of the current directory)
mkdir                   (Create new folder/s)
rmdir                   (Remove folder/s)
touch FILE              (create or update F)
cat                     (Concatenate and print (display) the content of files)
$ cat > FILE            (~ write and create..)  end: CTRL+C / CTRL+D
$ cat >> FILE           (~ add..)
$ cat F1 F2 > F3 (join)
$ echo "add line" >> FILE
printf
$ echo $((1+2))          -> 3

tee                     (Redirect output to multiple files)
echo program_usb_boot_mode=1 | sudo tee -a /boot/config.txt (add line)

sudo nano FILE / vi / gedit

cp F1 F2                (copy source destination) cp file.txt file-bak.txt
mv F1 F2                (move)
cmp F1 F2               (compare)
rm FILE                 (remove)
trash FILE              (x rm / apt install trash-cli)
$ trash-info / trash-put / trash-empty ...
echo file.txt byl > backup and delete
cat FILE | less / more

awk                     (Find and Replace text, database sort/validate/index)
$ awk '{print}' FILE = cat FILE
$ awk '{print $2}' FILE -> second column           ($0 = all,  $1 first, ...)
$ awk -F':' '{print $1,$7}' /etc/password          (-F: separator)
$ awk '/path {print $1,$2/1024"kB"}'  ls.txt       (size/1024 + kB)
$ awk '/path && $2 > 10000 {print $1,$2/1024"kB"}' (data > 10k ...) > path10.awk
$ awk -f path10k.awk ls_usr_bin.txt                (the same) 

sed                     (Stream editor for Replacing or substituting string)
$ echo "hello" | sed 's/hello/goodbye'              ->  goodbye
$ sed 's/unix/linux/g' file                        (Replace pattern unix -> linux)
$ sed 's/unix/linux/g' file > newfile              (s + delimiter: s/ s. s* ...)
$ sed -i 's/unix/linux/g' file (rewrite)
$ echo "Welcome To The Geek Stuff" | sed 's/\(\b[A-Z]\)/\(\1\)/g'
$ -> (W)elcome (T)o (T)he (G)eek (S)tuff
$ sed '5d' filename.txt                            (Delete 5th line)
$ sed '$d' filename.txt                            (Delete last line)

hexdump -C FILE
tr                     (translate or delete characters)
$ echo test | tr -d"t" >> es
$ echo -n "agama3" | sha256sum | tr -d "[:space:]-" >> correct hash
find
$ find /var/ | grep .service
locate STR 
wc FILE                (Print byte, word, and line counts)
grep FILE/EXPR         (history: g/re/p - print regul.expr.)
md5sum FILE
gpg                    (GnuPrivacy Guard)
$ gpg -c FILE          (~ encrypt F)
$ gpg file.gpg         (~ decrypt F)
find DIR/FILE          (Find files)
wget URL               (Retrieve web pages or files via HTTP, HTTPS or FTP)
$ wget -O https://raw.githubusercontent.com/octopusengine/linux/master/ct/btc.sh
scp                    (file transfer)
$ scp file user@url:   

dmesg                  (report sit.)
$ dmesg -H | grep X
sudo blkid
$ echo "& one more line" >> FILE / ~/name.txt

```

### Process / System / Logs
```bash
ps
$ ps afux                   (~ process - all tree user)
$ ps -ef | grep dpkg*       --> kill PID#
$ ps afx | grep py > ID     (process ID PID = $, $$ $PPID) 
$ ps aux | grep -i vi (-i ignore case)
$ ps axch -o cmd:16,%mem --sort=-%mem | head (top memory usage ps)
$ ps axch -o cmd:16,%cpu --sort=-%cpu | head (top cpu usage ps)
$ ps -e -o pid,ppid,uid,user,gid,group,pcpu,pmem,etime,tty,args
pstree
$ ptree -pa $$
pgrep -U "$USER"
kill ID / NAME
kill $(ps aux | grep ´...´ | awk ...)
killall
sysv-rc-conf (start init)
tail -f /var/log/uwsgi/app/*.log
seq [FIRST] [INCREMENT] LAST  (seq command in Linux is used to generate numbers from FIRST to LAST in steps of INCREMENT)
tqdm                        (progress bar)
$ seq 9999999 | tqdm --bytes | wc -l
$ tar -zcf - docs/ | tqdm --bytes --total `du -sb docs/ | cut -f1` > backup.tgz
top                         (	List processes running on the system)
htop                        (better top)
iotop
wiresharp-gtk
cron                        (Daemon to execute scheduled commands)
crontab                     (Schedule a command to run at a later time)
lsof                        (List open files)
lspci                       (List all PCI devices)
lsusb
lsmod
shutdown -h / -r            (Shutdown or restart linux)
reboot                      (Reboot the system)

systemd-cgls
system nginx status / start / stop / restart
systemctl status nginx
systemctl daemon-reload
$ systemctl list-units --type=service
$ systemctl list-units --type=target
$ systemctl status nginx    (status / enable / disable / start / stop / kill/ reload / restart)
$ systemctl add-wants mutli-user.target nginx.srevice

ls /etc/systemd/system
                      (init()=systemd)
service

--- logs ---
$ du -sh /var/log/syslog
$ journalctl --disk-usage    =    $ du -sh /var/log/journal
$ journalctl --vacuum-time=2d
$ journalctl --vacuum-size=100M


```

### bash script
```bash
$ bash <SCRIPT

$ chmod +x SCRIPT
$ ./SCRIPT             (= bash SCRIPT)

$ ./SCRIPT <&-           (&- = close i/o) 

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


