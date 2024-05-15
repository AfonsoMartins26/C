#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct palavras {
    char *palavra;
    int nOcorr;
    struct palavras *esq, *dir;
} *Palavras;

// Função para fazer uma rotação à direita
void rodaDireita(Palavras *a) {
    Palavras temp = (*a)->esq;
    (*a)->esq = temp->dir;
    temp->dir = *a;
    *a = temp;
}

// Função para fazer uma rotação à esquerda
void rodaEsquerda(Palavras *a) {
    Palavras temp = (*a)->dir;
    (*a)->dir = temp->esq;
    temp->esq = *a;
    *a = temp;
}

// Função para inserir uma nova palavra ou atualizar o número de ocorrências
void acrescentaPal(Palavras *p, char *pal) {
    if (*p == NULL) {
        // Árvore vazia, criamos um novo nó para armazenar a palavra
        *p = (Palavras)malloc(sizeof(struct palavras));
        (*p)->palavra = strdup(pal);
        (*p)->nOcorr = 1;
        (*p)->esq = (*p)->dir = NULL;
    } else {
        int cmp = strcmp(pal, (*p)->palavra);
        if (cmp < 0) {
            // A palavra é lexicograficamente menor, inserir à esquerda
            acrescentaPal(&((*p)->esq), pal);
            rodaDireita(p);
        } else if (cmp > 0) {
            // A palavra é lexicograficamente maior, inserir à direita
            acrescentaPal(&((*p)->dir), pal);
            rodaEsquerda(p);
        } else {
            // A palavra já existe na árvore, incrementar o número de ocorrências
            (*p)->nOcorr++;
        }
    }
}

// Função auxiliar para liberar a memória alocada pela árvore
void libertaArvore(Palavras p) {
    if (p != NULL) {
        libertaArvore(p->esq);
        libertaArvore(p->dir);
        free(p->palavra);
        free(p);
    }
}

int main() {
    // Exemplo de uso
    Palavras arvore = NULL;

    acrescentaPal(&arvore, "banana");
    acrescentaPal(&arvore, "maça");
    acrescentaPal(&arvore, "banana");
    acrescentaPal(&arvore, "laranja");
    acrescentaPal(&arvore, "maça");
    acrescentaPal(&arvore, "uva");

    // Exibindo o conteúdo da árvore
    printf("Palavras\tOcorrências\n");
    printf("-------------------------\n");
    printf("%-10s\t%d\n", arvore->palavra, arvore->nOcorr);
    printf("|-- %-10s\t%d\n", arvore->esq->palavra, arvore->esq->nOcorr);
    printf("|-- %-10s\t%d\n", arvore->dir->palavra, arvore->dir->nOcorr);

    // Liberar memória alocada pela árvore
    libertaArvore(arvore);

    return 0;
}
