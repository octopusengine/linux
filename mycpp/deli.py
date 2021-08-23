import os, sys, time, datetime

num = int(sys.argv[1]) 
print num

poc=num
deli = 2

while (poc>0):
   if (num%deli==0):
      print deli
   deli=deli+1   
   poc=poc-1

print "ok-hotovo"
