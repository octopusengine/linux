#!/bin/bash

echo "-----------------------"
echo "--- Test"
echo "-----------------------"


case $1 in
     -ssh) parametry=$1
           echo Ok -ssh;;

    -h|-H) echo $"--- Help:"$'\n'$"...todo ;-)";;

        *) echo "(try parameter -h for help)"

    exit 1;;
esac

echo $'\n'$"*** All done! ***"

exit
