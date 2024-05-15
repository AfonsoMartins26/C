#include <stdio.h>
#include <stdlib.h>

//Exame 2022

typedef struct LInt_nodo {
int valor;
struct LInt_nodo *prox;
} *LInt;

typedef struct ABin_nodo {
int valor;
struct ABin_nodo *esq, *dir;
} *ABin;

//1

int pesquisa (int a[], int N, int x){
  for(int i =0;i<N;i++){
    if(a[i] == x){
      return i;
    }
  }
  return -1 ;
}

//2

void roda (LInt *l){
    if (*l == NULL || (*l)->prox == NULL) {
        return;
    }

    LInt atual = *l;
    while (atual->prox->prox != NULL) {
        atual = atual->prox;
    }

    atual->prox->prox = *l;
    *l = atual->prox;
    atual->prox = NULL;
}

//3

int apaga(ABin *a, int n) {
    if (*a == NULL || n == 0) {
        return 0;
    }

    int apagados_esq = apaga(&((*a)->esq), n);
    int apagados_dir = apaga(&((*a)->dir), n - apagados_esq - 1);
    int total_apagados = apagados_esq + apagados_dir;

    if (total_apagados < n) {
        free(*a);
        *a = NULL;
        return total_apagados + 1;
    }

    return total_apagados;
}

//4

void checksum(char s[]) {
    int len = strlen(s);
    int soma = 0;

    for (int i = len - 1, j = 0; i >= 0; i--, j++) {
        int digito = s[i] - '0';
        if (j % 2 == 0) {
            digito *= 2;
            if (digito > 9) {
                digito = digito % 10 + digito / 10;
            }
        }
        soma += digito;
    }
    

    int digito_controle = 10 -(soma % 10);

    s[len] = digito_controle + '0';
    s[len + 1] = '\0';
}

//5

int escolhe(int N, int valor[], int peso[], int C, int quant[]) {
    int valor_total = 0;
    int peso_total = 0;

    for (int i = 0; i < N; i++) {
        quant[i] = 0;
    }

    for (int i = 0; i < N; i++) {
        if (peso_total + peso[i] <= C) {
            quant[i] = 1;
            valor_total += valor[i];
            peso_total += peso[i];
        }
    }

    return valor_total;
}