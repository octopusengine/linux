import time, socket, subprocess
import random, math

# dbl is compiled from double.c

print "double+1 c-test:"

#====== get procesor temp ============================
def getDouble(num): 
   print str(num)+" > ",	 
   try:
     pytemp = subprocess.check_output(['./dbl', str(num)], universal_newlines=True)
     print int(pytemp)+1
   #var_name = pytemp[:eq_index].strip()
   #value = pytemp[eq_index:eq_index+4]
   #numvalue=float(value)
   except:
   	  Err=True 
   	  print "Err"
   #  numvalue = -1
   #return numvalue 


getDouble(5)
getDouble(33)

#sudo python double.py

