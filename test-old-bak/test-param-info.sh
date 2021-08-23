#!/bin/bash

VERSION="0.1 - 2017"


arg_info() {

# use predefined variables to access passed arguments
#echo arguments to the shell
echo \$1 \$2 \$3 ' -> echo \$1 \$2 \$3'

# We can also store arguments from bash command line in special array
args=("$@")
#echo arguments to the shell
echo ${args[0]} ${args[1]} ${args[2]} ' -> args=("$@"); echo ${args[0]} ${args[1]} ${args[2]}'

#use $@ to print out all arguments at once
echo $@ ' -> echo $@'

# use $# variable to print out
# number of arguments passed to the bash script
echo Number of arguments passed: $# ' -> echo Number of arguments passed: $#'
}


dynamic_leave() {

i=0
  while [ "$i" -le 19 ]; do
    i=$((i + 1))
    echo -n "."
    sleep 0.1
  done
echo;

echo "--------------------"
echo "--- Test Complete --"
echo "--------------------"
exit
}

# _EOF_ / '_EOF_' 

print_help() {

cat << _EOF_

Usage:
   test [options]

Options:
   -h   print help and exit
   -i   basic info
   -v   print version and exit

_EOF_

}


if [ "$1" == "-i" ]; then
  arg_info
  exit
fi


if [ "$1" == "-a" ]; then
    ascii=~/mysh/ascii.txt
    echo $ascii
    cat $ascii

fi


if [ "$1" == "-h" ]; then
   print_help
   exit
fi


if [ "$1" == "-v" ]; then
   echo "version: " $VERSION
   echo
fi


dynamic_leave
# end
