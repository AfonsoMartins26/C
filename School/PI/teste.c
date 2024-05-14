#include <stdio.h>
#include <stdlib.h>

// Definição do tipo LInt
typedef struct LInt_nodo {
    int valor;
    struct LInt_nodo *prox;
} *LInt;

// Protótipo da função removeMaiores
LInt removeMaiores(LInt l, int x) {
    LInt inicio = NULL;
    LInt fim = NULL;

    while (l != NULL && l->valor <= x) {
        LInt novo = (LInt) malloc(sizeof(struct LInt_nodo));
        novo->valor = l->valor;
        novo->prox = NULL;

        if (inicio == NULL) {
            inicio = novo;
            fim = novo;
        } else {
            fim->prox = novo;
            fim = fim->prox;
        }
        l = l->prox;
    }

    while (l != NULL) {
        LInt temp = l;
        l = l->prox;
        free(temp);
    }

    return inicio;
}

// Função para imprimir uma lista ligada
void imprimirLista(LInt l) {
    while (l != NULL) {
        printf("%d -> ", l->valor);
        l = l->prox;
    }
    printf("NULL\n");
}

int main() {
    // Exemplos de uso da função removeMaiores

    // Criar uma lista de exemplo: 1 -> 3 -> 5 -> 7 -> 9 -> NULL
    LInt lista = (LInt) malloc(sizeof(struct LInt_nodo));
    lista->valor = 1;
    lista->prox = (LInt) malloc(sizeof(struct LInt_nodo));
    lista->prox->valor = 3;
    lista->prox->prox = (LInt) malloc(sizeof(struct LInt_nodo));
    lista->prox->prox->valor = 5;
    lista->prox->prox->prox = (LInt) malloc(sizeof(struct LInt_nodo));
    lista->prox->prox->prox->valor = 7;
    lista->prox->prox->prox->prox = (LInt) malloc(sizeof(struct LInt_nodo));
    lista->prox->prox->prox->prox->valor = 9;
    lista->prox->prox->prox->prox->prox = NULL;

    printf("Lista original: ");
    imprimirLista(lista);

    // Testar a função removeMaiores com x = 5
    int x = 5;
    LInt novaLista = removeMaiores(lista, x);

    printf("Lista após remover os maiores que %d: ", x);
    imprimirLista(novaLista);

    // Liberar a memória alocada para a lista original e a lista resultante
    while (lista != NULL) {
        LInt temp = lista;
        lista = lista->prox;
        free(temp);
    }
    while (novaLista != NULL) {
        LInt temp = novaLista;
        novaLista = novaLista->prox;
        free(temp);
    }

    return 0;
}

