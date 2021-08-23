#!/bin/sh

echo "cd>"
cd ..
cd my-python
echo "sudo>"



i=5
echo "zablikani $i krat"
while [ $i -gt 0 ]
do
  # sleep 1s
  echo -n "."
  i=`expr $i - 1`
  sudo ./blik.py

done
echo ""


exit 0