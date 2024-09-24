| [Directory struct](https://github.com/octopusengine/linux/blob/master/directory_struct.md) | [Disk](https://github.com/octopusengine/linux/blob/master/disk.md) | [Network](https://github.com/octopusengine/linux/blob/master/network.md) | [Multimedia](https://github.com/octopusengine/linux/blob/master/multimedia.md) | **App & Prog** | [Links](https://github.com/octopusengine/linux/blob/master/links.md) |

---

## Aplications and Programs

### Aps & Etc. (terminal)
```bash
tmux / ctrl+B / Create: % (-) " (|) ! (x) Next Prew >
terminator
tilix           (tiling terminal emulator)

~ terminal move: ctrl+ 🠖/🠔 / 
  ctrl+u (del rigt) / ctrl+k (delete from cursor to right)

$ sudo add-apt-repository universe (for ubuntu)
$ sudo apt install mc
mc              (norton commander - filesystem)
ranger          (console file manager with VI key bindings)
htop
btop
bpytop          ($ sudo pip3 install bpytop && sudo snap install bpytop)

sensors         (install lm-sensors)
neofetch        (system info)
pfetch          (simple neofetch)
scrot           (print screen)

$ toilet -f mono12 -F metal Tecmint.com
rig             (random identity)
fortune         (random quotes)
figlet Welcome
echo "octopusengine[dot]com is a community of Linux Nerds and Geeks" | pv -qL 10  (x ./baudprint.pl 600)
sl              (Steam Locomotive)
asciiquarium
cowsay Hello
$ cowsay -f ghostbusters Who you Gonna Call | lolcat (add usr/share/cowsay/cows/octopus.cow)
cowthink ...funny
tty-clock
aafire
asciiview elephant.jpg -driver curse

telnet towel.blinkenlights.nl
$ curl -u YourUsername:YourPassword -d status="message" http://twitter.com/statuses/update.xml
KeePassX         (password manager)

bc               (line calculator)
$ echo "12+5" | bc
$ echo "ibase=2; 11010010" | bc
$ hex="FF" && echo "obase=10;ibase=16;$hex" | bc  ( -> 255 )
$ echo "1==2" | bc           ( -> 0 )
$ echo "10>5" | bc           ( -> 1 )
$ pi=`echo "h=10;4*a(1)" | bc -l`    ( echo $pi -> 3.14...)

```

### Multimedia
```
<Photo management>
gthumb
digikam
kphotoalbum
darktable
shotwell

```

---

### bash / CPP / Python
```bash
#!bin/sh x #!bin/bash
$BASH (/usr/bin/bash) $SHELL (/bin/bash)
$HOME (/home/$USER) ($USER/$HOSTNAME $HOSTTYPE) $PATH
$EDITOR $BROWSER
$USER = logname / whoami
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



---
