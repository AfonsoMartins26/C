#include <stdio.h>

int main() {
    int count = 0;
    int n = 81;
    for(;n>0 ;n /=2) {
        count++;
    }
    printf("%d", count);
    return count;
}