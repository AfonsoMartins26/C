#include <stdio.h>

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
    printf("Onúmero da sequência de Fibonacci é: %d\n", fib2(n));
    return 0;
}