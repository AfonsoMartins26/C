#include <stdio.h>
#include <stdlib.h>

//teste 2022

typedef struct LInt_nodo {
int valor;
struct LInt_nodo *prox;
} *LInt;

//1

int nesimo(int a[], int N, int i) {
    ordena(a, N);
    return a[i - 1];
}

void ordena(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        for (int j = i; j < tamanho; j++) {
            if (vetor[i] > vetor[j]) {
                int temp = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = temp;
            }
        }
    }
}

//2

LInt removeMaiores(LInt l, int x) {
    LInt inicio = NULL;
    LInt fim = NULL;

    while (l != NULL && l->valor <= x) {
        LInt novo = (LInt) malloc(sizeof(struct LInt_nodo));
        novo->valor = l->valor;
        novo->prox = NULL;

        if (inicio == NULL) {
            inicio = novo;
            fim = novo;
        } else {
            fim->prox = novo;
            fim = fim->prox;
        }
        l = l->prox;
    }

    while (l != NULL) {
        LInt temp = l;
        l = l->prox;
        free(temp);
    }

    return inicio;
}

//3

