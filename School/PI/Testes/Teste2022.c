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

LInt novoNo(int valor) {
    LInt novo = (LInt) malloc(sizeof(struct LInt_nodo));
    novo->valor = valor;
    novo->prox = NULL;
    return novo;
}

LInt caminho(ABin a, int x) {
    if (a == NULL) {
        return NULL;
    }

    if (a->valor == x) {
        LInt lista = novoNo(x);
        return lista;
    }

    if (x < a->valor) {
        LInt lista = caminho(a->esq, x);
        if (lista != NULL) {
            LInt novo = novoNo(a->valor);
            novo->prox = lista;
            return novo;
        }
    } else {
        LInt lista = caminho(a->dir, x);
        if (lista != NULL) {
            LInt novo = novoNo(a->valor);
            novo->prox = lista;
            return novo;
        }
    }

    return NULL;
}

//4

void inc(char s[]){
      int l = strlen(s), i;

    for (i = l - 1; i >= 0 && s[i] == '9'; s[i--] = '0');

    if (i == -1) {
        s[0] = '1';
        s[l] = '0';
        s[l + 1] = '\0';
    } else {
        s[i]++;
    }
}

//5 implementacao razoavel 

int sacos(int p[], int N, int C){
  int soma = 0,count = 0;
  for(int i = 0;i <N ;i++){
    soma += p[i];
  }
  while (soma  >= C )
  {
    count++;
    soma = soma -C;    
  }
  if (soma == 0){
    return count;
  }
  else{
    return count+1;
  }
}
