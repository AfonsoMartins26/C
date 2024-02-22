#include <stdio.h>


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