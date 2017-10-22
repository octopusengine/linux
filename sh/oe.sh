#!/bin/bash
#oe / octopusengine
#wget https://raw.githubusercontent.com/octopusengine/linux/master/sh/oe.sh
#chmod 755 ../oe.sh

echo
if [[ $1 = "h" ]]; then
  echo "----- octopus engine help -----"
  echo "$1 h(help) / i(info)"
  echo "$2 m(raM/HD) / b(btc/ltc) / c(crypto test)"
fi

if [[ $1 = "i" ]]; then
  echo "----- octopus engine info -----"
  uname -a
  w=whoami
  echo "whoami > `$w`" 
  d=pwd
  echo "pwd > `$d`"
  sleep 1s  
fi

price1=123
if [[ $2 = "b" ]]; then
  echo "----- BTC/LTC -----"
  price1=$(wget -qO- https://www.bitstamp.net/api/v2/ticker/btcusd/ | grep -E -o 'last": "[0-9.]+"' | grep -E -o '[0-9]+.[0-9]{2}')
  echo "$price1 BTC/USD"
  sleep 1s
  price2=$(wget -qO- https://api.bitfinex.com/v1/pubticker/ltcusd | grep -E -o 'last_price":"[0-9.]+"' | grep -E -o '[0-9.]+')
  echo "$price2 LTC/USD"
  sleep 1s
fi

if [[ $2 = "c" ]]; then
  echo "----- crypto -----"
  echo -n "Test Hash" | sha256sum 
  i=0; while ! (echo -n "OctopusEngine$i" | sha256sum | tr -d "\n"; echo " (nonce=$i)")|grep -E "^00"; do let i++; done  
fi

if [[ $2 = "m" ]]; then
  echo "----- memory RAM..HD -----"
  echo "free>"
  free
  echo "dp -h>"
  df -h
fi

#if [[ $(which toilet) = "" ]]; then
#                echo $price
#        else
#toilet -t -f bigascii12 $price
#fi
#echo $x
#toilet -t -f bigascii12 $price1
