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

//1

//a
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

//b
int nFolhas(ABin a) {
    if (a == NULL)
        return 0;
    if (a->esq == NULL && a->dir == NULL)
        return 1;
    else
        return nFolhas(a->esq) + nFolhas(a->dir);
}

//c
ABin maisEsquerda(ABin a) {
    while (a != NULL && a->esq != NULL)
        a = a->esq;
    return a;
}

//d
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

//e
int procuraE(ABin a, int x) {
    if (a == NULL)
        return 0;
    if (a->valor == x)
        return 1;
    return procuraE(a->esq, x) || procuraE(a->dir, x);
}


//2

//f
struct nodo *procura(ABin a, int x) {
    if (a == NULL || a->valor == x)
        return a;
    if (x < a->valor)
        return procura(a->esq, x);
    else
        return procura(a->dir, x);
}

//g
int nivel(ABin a, int x) {
    if (a == NULL)
        return -1;
    if (a->valor == x)
        return 0;
    int nivel_esq = nivel(a->esq, x);
    int nivel_dir = nivel(a->dir, x);
    if (nivel_esq == -1 && nivel_dir == -1)
        return -1;
    else if (nivel_esq == -1)
        return nivel_dir + 1;
    else
        return nivel_esq + 1;
}

//h
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