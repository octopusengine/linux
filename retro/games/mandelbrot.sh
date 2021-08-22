#!/bin/bash
S0=S;S1=H;S2=E;S3=L;S4=L;
e=echo;b=bc;I=-1;
for x in {1..24};
do R=-2;
for y in {1..80};
do B=0;r=0;i=0;
while [ $B -le 32 ];
do r2=`$e "$r*$r"|$b`;i2=`$e "$i*$i"|$b`;i=`$e "2*$i*$r+$I"|$b`;
r=`$e "$r2-$i2+$R"|$b`;: $((B+=1));V=`$e "($r2 +$i2)>4"|$b`;

if [ "$V" -eq 1 ];
then break;fi;done; if [ $B -ge 32 ];then 
$e -n " ";
else U=$(((B*4)/15+30));$e -en "\E[01;$U""m";C=$((C%5));

eval "$e -ne \$E\$S$C";: $((C+=1));fi;R=`$e "$R+0.03125"|$b`
done;$e -e "\E[m\E(\r";I=`$e "$I+0.08333"|$b`;
done      #(c)BruXy

