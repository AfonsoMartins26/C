#include <stdio.h>

int main(){
  printf("I like Pizza");
  return 0;
}


/* isto é um comentário em c */

// isto é outro comentário em c

int dobro(int a){
  int r;
  r = 2*a;
  return r;
}

int dobro(int);

int manins() {	
int r;	
r = dobro(3);	
return 0;	
}