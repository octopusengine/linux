| [Directory struct](https://github.com/octopusengine/linux/blob/master/directory_struct.md) | [Disk](https://github.com/octopusengine/linux/blob/master/disk.md) | [Network](https://github.com/octopusengine/linux/blob/master/network.md) | [Multimedia](https://github.com/octopusengine/linux/blob/master/multimedia.md) | [App & Prog](https://github.com/octopusengine/linux/blob/master/app_prg.md) | [Links](https://github.com/octopusengine/linux/blob/master/links.md) |

---

## Directory sructure

### --- /bin ---

The **/bin** directory contains the essential user binaries (programs) that must be present when the system is mounted in single-user mode.

### --- /boot ---

Everything on your Linux system is located under the **/** directory, known as the **root** directory. You can think of the / directory as being similar to the C:\ directory on Windows — but this isn’t strictly true, as Linux doesn’t have drive letters. While another partition would be located at D:\ on Windows, this other partition would appear in another folder under / on Linux.

### --- /dev ---

Linux exposes devices as files, and the **/dev** directory contains a number of special files that represent devices. (Everything in Linux is a file.)

### --- /etc ---

The **/etc** directory contains **configuration files**, which can generally be edited by hand in a text editor.

/etc/hostname

/etc/password

/etc/shadow

/etc/fstab (*setup RAM-disk etc.*)

/etc/shells

/etc/samba/smb.conf

/etc/samba/smbusers

/etc/network

/etc/init.d/ssh start

/etc/nginx/nginx.conf 

/etc/tor/torrc 

### --- /home ---

The **/home** directory contains a home folder for each user. 

/home/USER/.bashrc   (*script after login*)

.ssh/known_hosts

.ssh/id_rsa

### --- /lib ---

The **/lib** directory contains **libraries** needed by the essential binaries in the **/bin** and **/sbin** folder. 
Libraries needed by the binaries in the */usr/bin* folder are located in */usr/lib*.

### --- /lost+found ---

If the file system crashes, a file system check will be performed at next boot. Any corrupted files found will be placed in the **/lost+found** directory, so you can attempt to **recover** as much data as possible.

### --- /media ---

### --- /opt ---

The **/opt** directory contains subdirectories for **optional software packages**. It’s commonly used by proprietary software.

### --- /proc ---

The **/proc** directory similar to the **/dev** directory because it doesn’t contain standard files. It contains special files that represent system and process information. (**Kernel and process files**)

/proc/cpuinfo

### --- /root ---

The **/root** directory is the home directory of the root user. Instead of being located at */home/root*, it’s located at **/root**. This is distinct from **/**, which is the system root directory.

### --- /run ---

### --- /sys ---

### --- /sbin ---

The **/sbin** directory is similar to the **/bin** directory. It contains essential binaries that are generally intended to be run by the root user for system administration.

### --- /tmp ---

Applications store **temporary files** in the **/tmp** directory. These files are generally deleted whenever your system is restarted and may be deleted at any time by utilities such as tmpwatch.

### --- /usr ---

The **/usr** directory contains **applications and files used by users**, as opposed to applications and files used by the system. 

/usr/bin/

/usr/man/

/usr/sbin/

/usr/bin/start_script

/usr/bin/uptime

/usr/bin/free (*memory usage*

### --- var ---

The **/var** directory is the writable counterpart to the **/usr** directory, which must be read-only in normal operation. Log files and everything else that would normally be written to **/usr** during normal operation are written to the **/var** directory. 

/var/log/... (logs)

/var/lib/tor/hidden_service/hostname

/var/www/html (nginx default web server) 
