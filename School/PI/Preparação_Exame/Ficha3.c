#include <stdio.h>


// 2

void swapM (int *x, int *y){
  int temp = *x;
  *x = *y;
  *y = temp;
}

// 3

void swap(int v[], int i, int j){
  int temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

//4

int soma (int v[], int N){
    int i = 0,soma = 0;
    for (i =0 ; i<N+1;i++){
        soma +=v[i];
    }
    return soma;
}

// 5

void inverteArray(int v[], int N) {
    int i, temp;
    for (i = 0; i < N / 2; i++) {
        temp = v[i];
        v[i] = v[N - i - 1];
        v[N - i - 1] = temp;
    }
}

// 6

int maximum (int v[], int N, int *m){
    if (N <=0) return 1;
    int maior = 0,i;
    for (i = 0; i < N+1 ; i++){
        if (v[i] > maior){
            maior = v[i];
        }
        
    }
    *m = maior;
    return 1;
}

// 7

void quadrados(int q[], int N) {
    q[0] = 0;
    int i;
    for (i = 1; i < N; i++) {
        q[i] = q[i-1] + (2 * (i-1) + 1);
    }
}

