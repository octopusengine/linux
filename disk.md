## Disk


<pre>
blkid                  (nlock device atributes)

lsblk                  (block device related info)


fdisk
cfdisk 
gparted                (gr. parti 


$ sudo mkfs.ext4 -L disk_name /dev/sdb1  (format)

mount DEV PATH  / sudo mount /dev/sdb1 usb-disk


df                     (space - disk free)

$ df -h                (-h human)


du -sh /dir/

$ du -s * | sort -nr > $HOME/user_space_report.txt


dd                     (disk dump) 




temporary RAMdisk:

$ mknod -m 660 /dev/ram b 1 1

$ chown root:disk /dev/ram
</pre>