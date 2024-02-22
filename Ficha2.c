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
    for(int i = 0 ; i < 8 ;i++ ){printf("%d %d\n", a, b);
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