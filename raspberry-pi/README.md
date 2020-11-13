# Raspberry pi

## Camera

```bash
sudo apt-get install fswebcam
sudo usermod -a -G video pi
   
fswebcam cam-test.jpg 
```


---

## Micropython

```bash
sudo apt-get install git
sudo apt-get install build-essential

sudo apt-get install libffi-dev

cd ~ 
git clone https://github.com/micropython/micropython.git

cd micropython 

cd ports 
cd unix
   
make clean
   

make axtls
   
cd ~
   
cd micropython
  
cd mpy-cross

make

cd ~  
cd micropython
cd ports
cd unix
make

./micropython 


>>>



```

---



