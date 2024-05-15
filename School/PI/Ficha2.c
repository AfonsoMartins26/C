#include <stdio.h> 

//1 

float multInt1(int n, float m) { // vai comecar a fazer r + m  em loop até que i seja igual a n-1 
      float r = 0;
      for (int i = 0; i < n; i++) {
          r += m;
      }
      return r;
}

float main (){
  printf("Introduza dois numeros : \n");
  int n;
  float m;
  scanf( "%d %f", &n,&m);
  float r;
  r = multInt1(n ,m );
  printf( "O resultado é %f.\n" ,r);
}

//2 
int contaasdivisoes(int n) {
    int count = 0;
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

//3 
int mdc1 (int a, int b){ // vai fazer o resto aé que o mesmo seja 0 aí o ultimo numero vai ser o mdc 
    int resto ; 
    do {
        resto = a %b;

        a = b;
        b = resto ;

    }while (resto != 0);

    return a;
}

/*exemplo para calcular o m.d.c 
m.d.c(54,21) 
54 = 2 *21 +12 
21 = 12*1 +9 
12 = 9*1 +3 
9 = 3 *3 + 0 
como o resto é zero o mdc(54,21)=3 */

int main (){
    int a ,b ;
    scanf ("%d,%d" ,&a ,&b ) ;
    int i =mdc1(a,b);
    printf("%d" , i);   
}

//4 
int mdc2 (int a, int b){
    for(int i = 0 ; i < 8 ;i++ ){
    if (a >b) {
        a = a-b;
        
    }
    else if (a < b){
        b = b - a;
    }
    else if (a == b){
        return a;
    }
    }

}

int main (){
    int a ,b;
    scanf ("%d %d" ,&a ,&b ) ;
    int i = mdc2(a,b);
    printf("%d" , i);   
}

//5 
int mdc3 (int a, int b){
    for(int i = 0 ; i < 8 ;i++ ){
    if (a == 0){
        return b;
    }
    else if (b == 0){
        return a;
    }
    else if (a >b) {
        a =a % b;
    }
    else if (a < b){
        b = b % a;
    }
    else if (a == b){
        return a;
    }
    }

}

int main (){
    int a ,b;
    scanf ("%d %d" ,&a ,&b ) ;
    int i = mdc3(a,b);
    printf("%d" , i); 
}

// 6

//a

int fib1(int n) {
    if (n < 2) {
        return 1;
    }
    else if (n >= 2) {
        return fib1(n-1) + fib1(n-2);
    }
}

int main() {
    int n;
    printf("Digite um número inteiro: ");
    scanf("%d", &n);
    printf("O %d-ésimo número da sequência de Fibonacci é: %d\n", n, fib1(n));
    return 0;
} 

//b 
int fib2(int n) {
    if (n < 2)
        return 1;

    int a = 1;  
    int b = 1;  
    int resultado = 0;

    for (int i = 2; i <= n; i++) {
        resultado = a + b;
        a = b;
        b = resultado;
    }

    return resultado;
}

int main() {
    int n;
    printf("Mete um numero : ");
    scanf("%d", &n);
    printf("O número da sequência de Fibonacci é: %d\n", fib2(n));
    return 0;
}