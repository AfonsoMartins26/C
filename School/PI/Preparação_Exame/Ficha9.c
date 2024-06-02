#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} *ABin;

ABin newABin (int r, ABin e, ABin d) {
ABin a = malloc (sizeof(struct nodo));
if (a!=NULL) {
a->valor = r; a->esq = e; a->dir = d;
}
return a;
}

// 1 

// a 

int altura(ABin a) {
    if (a == NULL)
        return -1;
    else {
        int altura_esq = altura(a->esq);
        int altura_dir = altura(a->dir);
        if (altura_esq > altura_dir)
            return altura_esq + 1;
        else
            return altura_dir + 1;
    }
}

// b

int nFolhas (ABin a){
    if (a == NULL) return -1;
    nFolhasaux(a,0);
}

int nFolhasaux (ABin a,int n){
    if ( a->esq == NULL && a->dir == NULL){
        return n+1;
    }
    else if ( a->esq != NULL && a->dir == NULL){
        nFolhasaux(a->esq , n);
    }
    else{
        nFolhasaux(a->dir , n);
    }
}

// c 

ABin maisEsquerda (ABin a){
    if ( a == NULL) return NULL;
    
    else if(a->esq == NULL) return a;
    
    else maisEsquerda (a->esq);
}

// d

void imprimeNivel(ABin a, int l) {
    if (a == NULL)
        return;
    if (l == 0)
        printf("%d ", a->valor);
    else {
        imprimeNivel(a->esq, l - 1);
        imprimeNivel(a->dir, l - 1);
    }
}

// e 

int procuraE(ABin a, int x) {
    if (a == NULL)
        return 0;
    if (a->valor == x)
        return 1;
    return procuraE(a->esq, x) || procuraE(a->dir, x);
}

// 2

// f 

struct nodo *procura(ABin a, int x) {
    if (a == NULL || a->valor == x)
        return a;
    if (x < a->valor)
        return procura(a->esq, x);
    else
        return procura(a->dir, x);
}

// g

int nivel (ABin a, int x){
    nivelaux(a,x,0);
}

int nivelaux(ABin a, int x, int nivel) {
    if (a == NULL) return -1;

    if (x == a->valor) return nivel;
    
    if ( x < a){
    int nivel_esq = nivelaux(a->esq, x, nivel + 1);
    if (nivel_esq != -1) return nivel_esq;
    }    

    else{
        if (nivelaux(a->dir, x, nivel + 1) != -1) return nivelaux(a->dir, x, nivel + 1);
    }
}

// h

void imprimeAte(ABin a, int x) {
    if (a == NULL)
        return;
    if (a->valor < x) {
        imprimeAte(a->esq, x);
        printf("%d ", a->valor);
        imprimeAte(a->dir, x);
    } else if (a->valor > x) {
        imprimeAte(a->esq, x);
    }
}