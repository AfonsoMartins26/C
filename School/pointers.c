#include <stdio.h>

void swap(int *x, int *y){
  int aux = *y;
  *y = *x;
  *x = aux;
}

int main(){
  int x =10 ,y =20 ;
  swap( &x,&y);
  printf("%d %d\n", x,y);
  return 0;
}