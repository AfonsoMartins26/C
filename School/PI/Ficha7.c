#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
char *palavra;
int ocorr;
struct celula * prox;
} * Palavras;

//1

void libertaLista (Palavras l){
	if(l != NULL){
		libertaLista(l->prox);
		free(l);
	}
}

//2 

int quantasP (Palavras l){
  int words = 0;

    while (l != NULL){
       words++;
       l = l->prox; 
    }
}

//3

void listaPal (Palavras l){
  while (l != NULL)
  {
    printf("Palavra: %s\n",l->palavra);
    printf( "ocorrencias: %d\n",l->ocorr );
    l = l->prox;
  }
  
}

//4

char * ultima (Palavras l){
	while(l->prox != NULL) {
  l = l->prox;
  }
	return l->palavra;
}

//5

Palavras novaCelula(char *p, int ocorr){
	Palavras nova = malloc(sizeof(struct celula));
	nova->prox = NULL;
	nova->palavra = strdup(p);
	nova->ocorr = ocorr;

	return nova;
} 

Palavras acrescentaInicio (Palavras l, char *p){
	Palavras nova = novaCelula(p, 1);

	nova->prox = l;

	return nova;
}

//6

Palavras acrescentaFim(Palavras l, char *p) {
    Palavras nova = novaCelula(p);
    if (l == NULL) {
        return nova;
    }
    Palavras temp = l;
    while (temp->prox != NULL) {
        temp = temp->prox;
    }
    temp->prox = nova;
    return l;
}


//7 

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


//8 

struct celula * maisFreq (Palavras l) {
    int max = 0;
    Palavras mais_freq = malloc(sizeof(struct celula));
    for (; l != NULL; l = l->prox) {
        if (l->ocorr > max) {
            max = l->ocorr;
            mais_freq = l;
        }
    }
    return mais_freq;
}