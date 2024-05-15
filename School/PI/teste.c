#include <stdio.h>
#include <stdlib.h>

typedef struct abin_nodo {
    int valor;
    struct abin_nodo *esq, *dir;
} *ABin;

// Função auxiliar para criar um novo nó da árvore
ABin novoNo(int valor) {
    ABin novo = (ABin)malloc(sizeof(struct abin_nodo));
    if (novo != NULL) {
        novo->valor = valor;
        novo->esq = NULL;
        novo->dir = NULL;
    }
    return novo;
}

ABin reconstroiRec(char s[], int *pos) {
    if (s[*pos] == '\0' || s[*pos] == '*') {
        (*pos)++;
        return NULL;
    }

    ABin no = novoNo(s[*pos] - '0');
    (*pos)++;
    no->esq = reconstroiRec(s, pos);
    no->dir = reconstroiRec(s, pos);

    return no;
}

ABin reconstroi(char s[]) {
    int pos = 0;
    return reconstroiRec(s, &pos);
}

void printArvore(ABin a, int nivel) {
    if (a == NULL)
        return;

    // Imprime espaços para indentação conforme o nível
    for (int i = 0; i < nivel; i++)
        printf("     ");

    // Imprime o valor do nó atual
    printf("%d\n", a->valor);

    // Imprime a subárvore esquerda
    printArvore(a->esq, nivel + 1);

    // Imprime a subárvore direita
    printArvore(a->dir, nivel + 1);
}


int main() {
    // Exemplo de uso da função reconstroi
    char s[] = "34**52**5*6**";
    ABin arvore = reconstroi(s);

    printf("Árvore formatada:\n");
    printArvore(arvore, 0);

    return 0;
}
