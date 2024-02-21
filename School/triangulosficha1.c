#include <stdio.h>
// 3 
void triang1(int n) {
    for(int i = 1; i < 2 * n; i++) {
        for(int j = 1; j <= 2 * n - i; j++) {
            if(j <= i) putchar('#');
        }
        putchar('\n');
    }
}

void  triang2 (int n) {
    int i, j, k;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n - i; j++)
            printf(" ");
        for (k = 1; k <= 2 * i - 1; k++)
            printf("#");
        printf("\n");
    }a
}

int main(int argc, char const *argv[])
{
    triang1(5);
    triang2(5);
    return 0;
}