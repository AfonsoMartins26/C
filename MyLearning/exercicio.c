#include <stdio.h> 

/*
Quadrado - Escrever um programa que mostre a seguinte figura no alto da tela:

XXXXX
X   X
X   X
X   X
XXXXX
*/

void main (){
   for (int j = 0 ;j <5 ; j++) 
   printf ("X");
   printf("\n");
   for (int i = 0 ;i<3;i++){
    for(int c=0;c <5;c ++)
    if (c == 0 ) printf("X");
    else if (c== 4) printf("X");
    else  printf(" ");
  printf("\n");
   }
   for (int j = 0 ;j <5 ; j++) 
   printf ("X");
   printf("\n");
}