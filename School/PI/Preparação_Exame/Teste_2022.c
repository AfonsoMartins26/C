#include <stdio.h>


// 1

int sort(int a, int b){
  return (a-b);
}

int nesimo(int a[], int N, int i){
    qsort(a, N, sizeof(int), sort);

    for ( int j = 0; j< N ; j++){
      if ( j-1 == i){
        return a[j-1];
      }
    }
    return -1;
}

// 2

typedef struct LInt_nodo {
int valor;
struct LInt_nodo *prox;
} *LInt;

LInt removeMaiores(LInt l, int x){
  LInt prev = NULL ,temp;
  while( l != NULL){
    if ( l->valor > x){
      if ( prev == NULL){
      temp = l;
      l = l->prox;
      free(temp);
      }
      else {
      temp = l ;
      l = l->prox;
      prev->prox = l;
      free(temp); 
      }
    }
    else{
      prev = l;
      l = l->prox;
    }
  }
  return l;
}

// 3

typedef struct ABin_nodo {
int valor;
struct ABin_nodo *esq, *dir;
} *ABin;

LInt caminho(ABin a, int x){
    
}