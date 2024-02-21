#include <stdio.h>


int mdc1 (int a, int b){ // vai fazer o resto aé que o mesmo seja 0 aí o ultimo numero vai ser o mdc 
    int resto ; 
    do {
        resto = a %b;

        a = b;
        b = resto ;

    }while (resto != 0);

    return a;
}

int main (){
    int a ,b ;
    scanf ("%d,%d" ,&a ,&b ) ;
    int i =mdc1(a,b);
    printf("%d" , i);   
}