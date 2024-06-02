#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} *ABin;

// 1 

// a 

ABin removeMenor (ABin *a){
  if (*a == NULL) return NULL;

  if ((*a)->esq == NULL){
    ABin temp = *a;
    *a = (*a)->dir;
    temp->dir = NULL;
    return temp;
  }

  else{
    removeMenor(&(*a)->esq);
  }
} 

// b

void removeRaiz(ABin *a) {
    ABin temp = *a;
    if ((*a)->esq == NULL)
        *a = (*a)->dir;
    else if ((*a)->dir == NULL)
        *a = (*a)->esq;
    else {
        temp = removeMenor(&(*a)->dir);
        temp->esq = (*a)->esq;
        temp->dir = (*a)->dir;
        *a = temp;
    }
    free(temp);
}

// c 

int removeElem (ABin *a, int x){
  if (*a == NULL) return 1;

  if ( *a == x) {
    removeRaiz(&(*a));
    return 0;
  }

  else if ( x < *a){
    removeElem(&(*a)->esq,x);
  }

  else{
   removeElem(&(*a)->dir,x);
  }
}

// 2

void rodaEsquerda (ABin *a){
ABin b = (*a)->dir;
(*a)->dir = b->esq;
b->esq = (*a);
*a = b;
}

void rodaDireita (ABin *a){
ABin b = (*a)->esq;
(*a)->esq = b->dir;
b->dir = *a;
*a = b;
}


// d

void promoveMenor(ABin *a) {
    if (*a == NULL || (*a)->esq == NULL) return;
    
    ABin *menor = a;
    while ((*menor)->esq != NULL) {
        menor = &((*menor)->esq);
    }
    
    if (menor == a) return;
    
    else {
        rodaDireita(a);
        menor = a;
        while ((*menor)->esq != NULL) {
            menor = &((*menor)->esq);
        }
    }
}

// e

void promoveMaior (ABin *a){
      if (*a == NULL || (*a)->dir == NULL) return;
    
    ABin *maior = a;
    while ((*maior)->dir != NULL) {
        maior = &((*maior)->dir);
    }
    
    if (maior == a) return;
    
    else {
        rodaDireita(a);
        maior = a;
        while ((*maior)->dir != NULL) {
            maior = &((*maior)->dir);
        }
    }
}

// f 

ABin removeMenor(ABin *a) {
    ABin atual = *a;
    while (atual->esq != NULL && atual->esq->esq != NULL)
        atual = atual->esq;
    if (atual->esq == NULL) {
        removeRaiz(a);
        return atual;
    } else {
        ABin temp = atual->esq;
        atual->esq = temp->dir;
        temp->dir = NULL;
        return temp;
    }
}


// 3

// Não quero fazer é muito fodida

