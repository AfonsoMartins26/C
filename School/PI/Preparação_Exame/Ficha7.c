#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
char *palavra;
int ocorr;
struct celula * prox;
} * Palavras;

//1

void libertaLista (Palavras l){
      Palavras temp ;
      while(l != NULL){
      temp = l;
      free(temp->palavra);
      free(temp);
      l = l->prox;
      }
}

// 2 

int quantasP(Palavras l) {
    int count = 0;
    while (l != NULL) {
        count++;
        l = l->prox;
    }
    return count;
}

// 3

void listaPal (Palavras l){
  while(l != NULL){
    printf("%s"l->palavra);
    printf("\t%d\n"l->ocorr);
    l = l->prox;
  }
}

// 4 

char * ultima (Palavras l){
  while(l->prox != NULL){
    l = l->prox;
  }
  return l->palavra;
}


// 5

Palavras acrescentaInicio (Palavras l, char *p){
  Palavras inicio;
  inicio = malloc(sizeof(struct celula));
  inicio->palavra = *p;
  inicio->prox = l;
  inicio->ocorr= 1;
  return inicio;
}

// 6 

Palavras acrescentaFim (Palavras l, char *p){
  Palavras fim;
  fim = malloc(sizeof(struct celula));
  fim->palavra = *p;
  fim->ocorr = 1;
  fim->prox = NULL;
  l->prox = fim;
  return l;
}

// 7

Palavras acrescenta (Palavras l, char *p) {
    Palavras novo = (Palavras) malloc(sizeof(struct celula));
    novo->palavra = p;
    novo->ocorr = 1;
    novo->prox = NULL;
    Palavras atual = l;
    while (atual->prox != NULL) {
        if (strcmp(atual->palavra, p) == 0) {
            atual->ocorr++;
            return l;
        }
        atual = atual->prox;
    }
    if (strcmp(atual->palavra, p) == 0) {
        atual->ocorr++;
        return l;
    }
    atual->prox = novo;
    return l;
}

// 8 

struct celula * maisFreq (Palavras l) {
    int max = 0;
    Palavras mais_freq = malloc(sizeof(struct celula));
    while(l != NULL) {
        if (l->ocorr > max) {
            max = l->ocorr;
            mais_freq = l;
        }
    }
    return mais_freq;
}