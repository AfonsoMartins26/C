#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} *ABin;

// (a) removeMenor
ABin removeMenor(ABin *a) {
    if ((*a)->esq == NULL) {
        ABin temp = *a;
        *a = (*a)->dir;
        temp->dir = NULL;
        return temp;
    }
    return removeMenor(&(*a)->esq);
}

// (b) removeRaiz
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

// (c) removeElem
int removeElem(ABin *a, int x) {
    if (*a == NULL)
        return 0;
    if ((*a)->valor == x) {
        removeRaiz(a);
        return 1;
    }
    if ((*a)->valor > x)
        return removeElem(&(*a)->esq, x);
    else
        return removeElem(&(*a)->dir, x);
}

// (d) promoveMenor
void promoveMenor(ABin *a) {
    if (*a == NULL || (*a)->esq == NULL)
        return;
    rodaDireita(a);
}

// (e) promoveMaior
void promoveMaior(ABin *a) {
    if (*a == NULL || (*a)->dir == NULL)
        return;
    rodaEsquerda(a);
}

// (f) removeMenor (alternativa)
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


// (g) constroiEspinha
int constroiEspinhaAux(ABin *a, ABin *ult) {
    if (*a == NULL) 
        return 0;
    int count = constroiEspinhaAux(&((*a)->esq), ult);
    if (count == 0)
        *ult = *a;
    else {
        (*ult)->dir = *a; // armazenamos o resultado maior mais á direta
        *ult = *a; // e de seguida voltamos para cima para que os elementos estejam ordenados
    }
    (*a)->esq = NULL;
    return count + 1;
}

int constroiEspinha(ABin *a) {
    ABin ult = NULL;
    return constroiEspinhaAux(a, &ult);
}

// (h) equilibraEspinha esta não percebi muito bem 
ABin equilibraEspinha(ABin *a, int n) {
    if (n <= 0) return NULL;
    int m = n / 2;
    ABin espinha = *a;
    ABin novaRaiz = espinha;
    for (int i = 0; i < m; i++) {
        novaRaiz = espinha->dir;
        rodaEsquerda(&espinha);
    }
    novaRaiz->esq = equilibraEspinha(a, m);
    novaRaiz->dir = equilibraEspinha(&(novaRaiz->dir), n - m - 1);
    return novaRaiz;
}

// (i) equilibra
void equilibra(ABin *a) {
    int n = constroiEspinha(a);
    *a = equilibraEspinha(a, n);
}

// Função rodaEsquerda e rodaDireita
void rodaEsquerda(ABin *a) {
    ABin b = (*a)->dir;
    (*a)->dir = b->esq;
    b->esq = *a;
    *a = b;
}

void rodaDireita(ABin *a) {
    ABin b = (*a)->esq;
    (*a)->esq = b->dir;
    b->dir = *a;
    *a = b;
}

// Função auxiliar para remoção do maior elemento
ABin removeMaior(ABin *a) {
    if ((*a)->dir == NULL) {
        ABin temp = *a;
        *a = (*a)->esq;
        temp->esq = NULL;
        return temp;
    }
    return removeMaior(&(*a)->dir);
}
