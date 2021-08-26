#!/usr/bin/env python3

"""
simple test: 2018/02

progressbar:
$ pip3 install tqdm

=== run ===
$ python3 simple.py

=== or ===
sudo chmod +x simple.py
$ ./simple.py
"""

import os, sys
from tqdm import tqdm


param = sys.argv[1]

if param == "-h":
   print("[ help ]")
   print("Brute force search for a prime number")
   print("(Only simple python example)")
   print("Single parameter: your number")
   print()

else:

  try:
    numi = int(param)
    deli = 2
    prime = True
    print("[ divisions ]")

    for num in tqdm(range(numi-2)):
       if (numi%deli==0):
           print(deli, end=" | ")
           prime = False
       deli = deli+1

    if prime: print("none")
    print()
    print("Number:", numi, end=" ")
    if prime: print("is prime.")

  except:
    print('[ err ]')
    print("Parameter must be a number.")

  print()
  print("[ end ]")
