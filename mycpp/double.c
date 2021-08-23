/*#Extending Python with C*/
/*#include "Python.h"*/

//magpi 47-49 /str.cca 46
#include <stdio.h>  //printf
#include <stdlib.h> //system

int main ( int argc, char *argv[] )
{   
   int num=atoi(argv[1]);	
	
   printf("%d\n",num*2);
   
   return(0);   
}


/*
compile:
gcc -o myprog 01haloo.c
gcc -o myprog 02scr.c -lm

run:
./myprog
*/



