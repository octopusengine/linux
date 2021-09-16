## Disk

```bash
lsblk                            (block device related info)
blkid                            (block device atributes)

--- ext4 ---
$ dumpe2fs /dev/sda1 | head -n 30 (file sysem of first disk.. -h / ext4 super block)
$ ls -li                         (id mum ...)
$ stat FILE.iso                  (size, blocks, reg.file, ...)
$ sudo fsck /dev/sdb1            (lsblk > ...)
$ sudo tune2fs -m 0 /dev/sdb2    (tweak file system param. and adjust reserved space 0% for the system)
$ sudo e4defrag -c /             (check foor file syst > need defragmentation?)

fdisk                            (Partition table manipulator) 
$ sudo fdisk -l

less /etc/fstab

cfdisk                           (Partition table manipulator for Linux)
$ cfdisk /dev/sda

gparted                          (gr. Partition table manipulator)

mkfs                             (make file systems)
$ sudo mkfs.ext4 -L disk_name /dev/sdb1  (formating: ext2/3/4 bfs/fat/nfts/vfat/msdos...)
...    mkfs.bfs                          (bfs boot file system) 

mount DEV PATH          (Mount a file system - device + path)
$ sudo mount /dev/sdb1 usb-disk
$ sudo mount -a / /media/usb1t

ddrescue                (Data recovery tool)

df                      (space - disk free)
$ df -h                 (-h human)
 
du -sh /dir/
$ du -s * | sort -nr > $HOME/user_space_report.txt
$ du -shBM /var/ | sort -n

dd if=source of=dest                             (disk dump - of "dest" defines the file or location where you want your data saved) 
$ dd if=/dev/sda of=/dev/sdb
$ dd if=/dev/sda of=/home/username/sdadisk.img
$ dd if=sdadisk.img of=/dev/sdb
$ dd if=/dev/zero of=/dev/sda1                   (wiping)
$ dd if=/dev/urandom | pv | dd of=/dev/sda1      (monitoring)
$ dd bs=4M of=/dev/sdb if=/path/to/my_backup.img (raspberry bak)

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
