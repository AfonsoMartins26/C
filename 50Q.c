#include <stdio.h> 

//1 

int prim(){
    int n,max=0;
    while(n != 0){
        scanf("%d", &n);
        if(n > max) max = n;
    }
    return max;
}

//2 

int sec(){
  int n=1, i = 0;
  float media = 0; 
  while(n != 0){
    scanf("%d" ,&n);
    media  += n;
    i ++ ; 
  }
  t = media / i ;
  return t ;
}

//3 

int three(){
  int n , max = 0,max2 = 0; 
  while(n != 0){
    scanf("%d" ,&n);
    if ( n>= max){
      max2 = max ; 
      max = n;
    }
    else if (n >=max2){
      max2 = n;
    }
  }
  return max2 ; 
}

//4 

int bitsUm(unsigned int n) {
    int count = 0;
    while (n != 0) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

int main() {
    unsigned int num;
    printf("Digite um número sem sinal: ");
    scanf("%u", &num);
    printf("O número de bits iguais a 1 é: %d\n", bitsUm(num));
    return 0;
}

//5 