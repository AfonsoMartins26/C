#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipos.h"


typedef struct LInt_nodo {
int valor;
struct LInt_nodo *prox;
} *LInt;

int nesimo_sol(int a[], int N, int i){
	// adaptação de minSort
	int j,k, m;
	for (j=0; ja[k];j++){ m=k;
		if (m!=j) swap (a,m,j);
	}
	return a[j-1];
}

LInt removeMaiores1_sol (LInt l, int x){
	LInt *r=&l, a, aux;
	while (*r != NULL && (*r)->valor <= x)
		r = &((*r)->prox);
    
    a = *r;
    *r = NULL;
    while (a != NULL){
    	aux = a;
      a=a->prox; 
      free (aux);
    }
   	return l;
}

LInt removeMaiores_sol (LInt l, int x){
	LInt pt = l, ant = NULL;
	// fase 1: avançar
	while (pt!=NULL && pt->valor <= x){
		ant = pt; pt = pt->prox;
	}
	// fase 2: terminar a lista resultante
	if (ant == NULL) l = NULL;
	else ant->prox = NULL;
	// fase 3: libertar o resto da lista
	while (pt != NULL) {
		ant = pt; pt = pt->prox; free (ant);
	}
	return l;
}

LInt caminho_sol (ABin a, int x){
	LInt r=NULL;
	if (a!=NULL){
		if (a->valor == x) r = newLInt (a->valor,NULL);
		else { 
			if (x == a->valor) r = caminho_sol (a->esq,x);
			else r = caminho_sol (a->dir,x);
			if (r != NULL) r = newLInt (a->valor,r);
		}
	}
	return r;
}

void inc_sol(char s[]) {
	int l = strlen(s), i;

	for (i = l-1; i>=0 && s[i] == '9'; s[i--]='0');
	// caso particular: a string aumenta de tamanho
	if (i==-1) { s[0] = '1'; s[l] = '0'; s[l+1]='\0';}
    else s[i]++;
}

int ensacarAux_sol (int p[], int N, int k, int i, int pesos[]){
    // admitindo que os i primeiros items já 
    // se encontram em sacos, tenta ensacar os restantes.
    // Significado do array pesos:
    //     pesos[j] tem a capacidade disponível do saco j
    int j;
    if (i==N) return 1;
    // tentar guardar o item i (com todas as alternativas) 
    // e depois (recursivamente) os restantes
    for (j=0; j= p[i]) {
    		// se o item i cabe no saco j
    		pesos[j] -= p[i];
    		// coloca-se no saco j e tenta-se o 
    		// resto dos items
    		if (ensacarAux_sol (p,N,k,i+1,pesos)) return 1;
    		// Se não houve solução, retira-se para 
    		// tentar outras alternativas
    		pesos[j] += p[i];
    	}
    // Se nada funcionou ...
    return 0;
}

int ensacar_sol (int p[], int N, int C, int k) {
	// true se é possível ensacar com k sacos
	int pesos [k]; int i;
	for(i = 0; i < k; pesos[i++] = C)
		;
	// true sse é possível ensacar em k sacos
	return ensacarAux_sol (p,N,k,0,pesos);
}

int sacos_sol (int p[], int N, int C){
	int i=0;
	while (! ensacar_sol (p,N,C,i)) i++;
	return i;
}
