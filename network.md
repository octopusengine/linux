| [Directory struct](https://github.com/octopusengine/linux/blob/master/directory_struct.md) | [Disk](https://github.com/octopusengine/linux/blob/master/disk.md) | **Network** | [Multimedia](https://github.com/octopusengine/linux/blob/master/multimedia.md) | [App & Prog](https://github.com/octopusengine/linux/blob/master/app_prg.md) | [Links](https://github.com/octopusengine/linux/blob/master/links.md) |

---

## Network

```bash
hostname 
RPi: myPiName - /etc/hostname
ifconfig
$ ifconfig | grep broadcast | awk '{print $2}'   (get IP)
hostname -I                                      (get IP)
$ alias ipaddress="ifconfig | grep broadcast | awk `{print $2}`" 
$ alias ipaddress="echo $(ifconfig | grep broadcast | awk `{print $2}`)" 
ethtool eth()
ip addr
$ ip address | grep eth0 | grep inet
curl [options] URL -- dtata transfer (HTTP, FTP, IMAP, POP3, SCP, SFTP, SMTP, TFTP, TELNET, LDAP or FILE)
$ curl -s "https://api.chucknorris.io/jokes/random" | jq -r '.value'

speedtest
nc (net cat / listen / connect)

iftop
sudo route -n
ping host-IP
$ ping -c 5 google.com / 8.8.8.8

whois domain
dig domain      (DNS lookup)
dig -x host     (reverse lookup)
traceroute      (Trace Route to Host)
mtr             (Network diagnostics - traceroute/ping)
ip a l / a s    (addr show)
arp             (ip & MAC addr. with robust feature set)
$ arp -a        (display all hosts in alternative BSD style)
$ more /etc/hosts

nmap            (network mapper)
$ nmap - sn / -v -A / -sP 192.168.0.*
$ nmap - sT -p80,433 192.168.0.* | grep report (scan TCP-IP for port)

netstat         (Networking connections/stats / install net-tools)
$ netstat -vat / -nr / -i / -ta 
$ netstat -tulpn  (ports)

bsh-write       (send message)

ssh
$ sudo apt-get install openssh-server
$ service ssh start
$ /etc/init.d/ssh start
$ ssh-copy-id
$ ssh IP / ssh USER@IP
$ logout

$ ssh-keygen -b 4096
--> priv.key: id_rsa
--> publ.key: id_rsa.pub
$ ssh-copy-id USER@IP

ssh-tor (open port for tor: in ..torrc)
$ torify ssh USER@HOSTNAME.onion

ssh config
$ nano ~/.ssh/config
$ chmod 600 ~/.ssh/config

Host pi-home
    HostName 192.168.x.y
    User pi
    Port 22
    IdentityFile ~/.ssh/id_rsa
Host internal-*
    ProxyJump jumpuser@gateway.example.com
    User internaluser
$ ssh pi-home

$ scp USER@IP_ADDR:/home/USER/FILE.src FILE.dest                  (netw copy)
$ scp -v username@from_host:file.txt /local/directory/            (-v Verbose mode) 
$ scp file.txt username@to_host:/remote/directory/
$ scp -r username@from_host:/remote/directory/  /local/directory/ (–r Recursively copy entire directories)
$ scp -r /local/directory/ username@to_host:/remote/directory/
$ scp username@from_host:/remote/directory/file.txt username@to_host:/remote/directory/

sftp IP  (secure FTP) 
> ls/lls / pwd/lpwd / cd/lcd
> get FILE / -r DIR
> put FILE
> bye

python3 -m http.server
>> browser: http://IP_ADDR:8000/

e-mail
mutt            (terminal e-mail - IMAP, SMTP)
$ .config/mutt / man neomutt / -- home/user/Mail/
$ mutt 

$ sudo ifdown eth0 && sudo ifup eth0 (restart wifi)
$ nohup (no hangup)
$ sudo nohup sh -c "ifdown eth0 && ifup eth0"
```
