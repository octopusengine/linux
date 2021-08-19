## Disk

```bash
blkid                  (block device atributes)
lsblk                  (block device related info)

fdisk                  (Partition table manipulator for Linux)                 

cfdisk                 (Partition table manipulator for Linux)
$ cfdisk /dev/sda

gparted                (gr. parti 

mkfs                   (make file systems)
$ sudo mkfs.ext4 -L disk_name /dev/sdb1  (formating: ext2/3/4 bfs/fat/nfts/vfat/msdos...)
...    mkfs.bfs                          (bfs boot file system) 

mount DEV PATH  / sudo mount /dev/sdb1 usb-disk

ddrescue               (Data recovery tool)

df                     (space - disk free)
$ df -h                (-h human)

du -sh /dir/
$ du -s * | sort -nr > $HOME/user_space_report.txt

dd if=source of=dest                           (disk dump - of "dest" defines the file or location where you want your data saved) 
$ dd if=/dev/sda of=/dev/sdb
$ dd if=/dev/sda of=/home/username/sdadisk.img
$ dd if=sdadisk.img of=/dev/sdb
$ dd if=/dev/zero of=/dev/sda1                 (wiping)
$ dd if=/dev/urandom | pv | dd of=/dev/sda1    (monitoring)

$ dd if=/dev/zero of=~/howtogeek.img bs=1M count=250   (block size of 1 MB x 250. This will give us a file system of 250 MB)
$ mkfs.ext2 ~/howtogeek.img
$ sudo mkdir /mnt/geek
$ sudo mount ~/howtogeek.img /mnt/geek
$ sudo chown dave:users /mnt/geek/
...
$ sudo umount /mnt/geek


temporary RAMdisk:
$ mknod -m 660 /dev/ram b 1 1
$ chown root:disk /dev/ram
```
