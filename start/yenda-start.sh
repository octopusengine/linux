#!/bin/bash

# /etc/systemd/system/yenda.service >
# sudo systemctl start yenda

# usr/local/bin/yenda-start.sh | chmod 744 yenda-start.sh
# add >> / rewrite >

date > ./home/yenda/disk_space_report.txt
du -sh /home/ >> ./home/yenda/disk_space_report.txt
