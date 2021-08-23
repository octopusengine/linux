/*#Extending Python with C*/
/*#include "Python.h"*/

//magpi 47-49 /str.cca 46
#include <stdio.h>  //printf
#include <stdlib.h> //system
#include <math.h> // nutno pridat -lm (separatni klihovna?)
//#include <time.h>
#include <unistd.h> //sleep

#define PI 3.14159265


//asi je vhodne aby fce byla deklarovana pred prvnim pouzitim
void clrscr(void)
{
   //system("@cls||clear"); //+pro win
   system("clear");   
}


double main(void)
{
   int a;
   int b=99;
   double val = PI / 180;
   
   
   double n=12;
   double s;
   s=sin(n*val); 
   
   char c;
   
   a=0;


   printf("Ahoj C\n");
   printf("123\n %d %d %f",a,b,s);
   // %d decimal, %f float
   
   c = getchar();
   
   
   if (a==0)
   { printf("\n a je nula\n"); }
   
   while (a<6)
   {
     printf("a=%d\n",a);
     a++;
   }
   
   clrscr(); 
   
    while (b>0)
   { 
	 //clrscr();
	 s=sin(b);
     usleep(1000 * 10);//*ms
     clrscr(); 
     printf(" %d %f\n",b,s);
     b--;
     //sleep(1); //int sec
     
   }
   
   printf("\n");
   putchar(c);
   printf("\n");
   
   return(0);
   
}


/*
compile:
gcc -o myprog 01haloo.c
gcc -o myprog 02scr.c -lm

run:
./myprog
*/



