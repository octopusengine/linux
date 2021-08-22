#!/bin/bash


# ... /home/yenda/mysh/btc.sh price usd

if [ "$1" = "price" ]; then
        currency=$([ "$2" = "" ] && echo "usd" || echo $2)

        case $2 in
                ltc)
                        pair="$2/usd"
                        ;;
                eur|*)
                        pair="btc/$currency"
                        ;;
        esac

        echo "Fetching the current $pair price..."

        case $2 in
                eur)
                        price=$(wget -qO- https://www.bitstamp.net/api/v2/ticker/btceur/ | grep -E -o 'last": "[0-9.]+"' | grep -E -o '[0-9]+.[0-9]{2}')
                        price="$price EUR"
                        ;;
                ltc)
                        price=$(wget -qO- https://api.bitfinex.com/v1/pubticker/ltcusd | grep -E -o 'last_price":"[0-9.]+"' | grep -E -o '[0-9.]+')
                        price="\$$price"
                        ;;
                *)
                        price=$(wget -qO- https://www.bitstamp.net/api/v2/ticker/btcusd | grep -E -o  'last": "[0-9.]+"' | grep -E -o '[0-9]+.[0-9]{2}')
                        price="\$$price"
                        ;;
        esac

        if [[ $(which toilet) = "" ]]; then
                echo $price
        else
                toilet -t -f bigascii12 $price
        fi
else
        echo "No argument provided. 
        echo "Try: ...PATH/btc.sh price usd"
fi

