#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//Exame 2021 

//1

int paresImpares(int v[], int N) {
    int pares = 0;
    int indice_par = 0;

    for (int i = 0; i < N; i++) {
        if (v[i] % 2 == 0) {
            int temp = v[indice_par];
            v[indice_par] = v[i];
            v[i] = temp;
            pares++;
            indice_par++;
        }
    }

    return pares;
}

//2

typedef struct LInt_nodo {
int valor;
struct LInt_nodo *prox;
} *LInt;

void merge(LInt *r, LInt a, LInt b) {
    LInt temp = malloc(sizeof(struct LInt_nodo));
    *r = temp;

    while (a != NULL && b != NULL) {
        if (a->valor < b->valor) {
            (*r)->prox = a;
            a = a->prox;
        } else {
            (*r)->prox = b;
            b = b->prox;
        }
        *r = (*r)->prox;
    }
    
    (*r)->prox = (a != NULL) ? a : b;
    *r = temp->prox;
    free(temp);
}

//3

void latino (int N, int m[N][N]){
  int i ,j,k= 1;
  for (j = 0; j < N ; j++){
    for (i = 0 ;i < N ;i++){
      m[j][i]=k;
      k++;
    }
  }
}

//4 não sei se percebi bem

typedef struct nodo {
int valor;
struct nodo *pai, *esq, *dir;
} *ABin;

ABin next(ABin a) {
    if (a->dir != NULL) {
        a = a->dir;
        while (a->esq != NULL)
            a = a->esq;
        return a;
    }

    while (a->pai != NULL && a->pai->valor < a->valor)
        a = a->pai;

    return a->pai;
}

//5 não sei se está certo 

typedef struct palavras {
char *palavra;
int nOcorr;
struct palavras *esq, *dir;
} *Palavras;

void acrescentaPal(Palavras *p, char *pal) {
    if (*p == NULL) {

        *p = (Palavras)malloc(sizeof(struct palavras));
        (*p)->palavra = strdup(pal);
        (*p)->nOcorr = 1;
        (*p)->esq = (*p)->dir = NULL;
    } else {
        int cmp = strcmp(pal, (*p)->palavra); //compara as palavras dá menor que 0 se pal for menor que (*p)->palavra e > 0 se o contrario  
        if (cmp < 0) {

            acrescentaPal(&((*p)->esq), pal);
        } else if (cmp > 0) {

            acrescentaPal(&((*p)->dir), pal);
        } else {

            (*p)->nOcorr++;
        }
    }
}