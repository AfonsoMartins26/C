#include <stdio.h>

int contaasdivisoes() {
    int count = 0;
    int n = 81;
    for(;n>0 ;n /=2) {
        count++;
    }
    return count;
}

float multInt2(int n, float m) {
    float result = 0;
    int i;
    int operations = 0;
    int r = contaasdivisoes (n);
    if (n%2 ==1) result = m; 
    for (i = 0; i < r; i++) {
       m *= 2;
       n /=2;
        if (n%2 == 1) { 
            result += m;
            operations++; 
        } 
    }
    return result;
}
    


float main (){
  printf("Introduza dois numeros : \n");
  int n;
  float m;
  scanf( "%d %f", &n,&m);
  float r;
  r = multInt2(n ,m );
  printf( "O resultado é %f.\n" ,r);
}