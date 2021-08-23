#!/bin/sh

# #je REM //
#http://www.root.cz/clanky/programovani-v-bash-shellu/

#hlavni systemove prom.
echo Prave provadeny skript $0
echo Prvni argument $1

#promenne
promennaA=123
promennaB=$promennaA
echo Hodnota druhe promenne je: $promennaB

#vstup
echo Zadej cislo:
read promenna1


i=10
echo "Nemame kam spechat, pockame $i sekund"
while [ $i -gt 0 ]
do
  sleep 1s
  echo -n "."
  i=`expr $i - 1`
done
echo ""
echo "no tak budeme pokracovat, no."


cesta=/home/
skupina=my-script
echo Seznam souboru v adr. $skupina:
ls ${cesta}pi/$skupina

exit 0