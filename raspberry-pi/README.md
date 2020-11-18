# Raspberry pi

## Config


```bash
sudo raspi-config
```

-> /boot/config.txt


```
|        1 Change User Password Change password for the current user                               │
│        2 Network Options      Configure network settings                                         │
│        3 Boot Options         Configure options for start-up                                     │
│        4 Localisation Options Set up language and regional settings to match your location       │
│        5 Interfacing Options  Configure connections to peripherals                               │
│        6 Overclock            Configure overclocking for your Pi                                 │
│        7 Advanced Options     Configure advanced settings                                        │
│        8 Update               Update this tool to the latest version                             │
│        9 About raspi-config   Information about this configuration tool  
```

---

## GPIO

```bash
sudo apt update
sudo apt install python3-gpiozero
or
sudo pip3 install gpiozero
```

gpiozero: https://gpiozero.readthedocs.io/en/stable/


---

## Camera

```bash
sudo apt-get install fswebcam
sudo usermod -a -G video pi
   
fswebcam cam-test.jpg 
```


---

## Python

```bash
sudo apt install python3 pip3

```

---

## Micropython

### install

```bash
sudo apt-get install git
sudo apt-get install build-essential

sudo apt-get install libffi-dev

cd ~ 
git clone https://github.com/micropython/micropython.git

cd micropython/ports/unix
make clean
make axtls
   
cd ~   
cd micropython
  
cd mpy-cross
make

cd ~  
cd micropython/ports/unix
make

./micropython 

>>>

ctrl+D


```

### py->mpy

```
cd micropython/mpy-cross 
./mpy-cross ../../py-mpy/test.py

```


---



