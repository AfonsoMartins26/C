#include <stdio.h>

int bitsUm(unsigned int n) {
    int count = 0;
    while (n > 0) {
        if ( n %2 == 1) count++ ;
        n = n/2;
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

