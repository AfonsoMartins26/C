#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//Teste2021

//1

int sumhtpo(int n) {
    int r = 0;
    int contador = 0;

    while (n != 1 && contador < 100) {
        contador++;
        r += n;
        if (n % 2 == 0)
            n = n / 2;
        else
            n = 1 + (3 * n);
    }

    if (contador < 100) {
        return -1;
    } else {
        return r;
    }
}


//2

//já fiz noutro teste 


//3

//facil 

//4

int freeAB(ABin a) {
    if (a == NULL) {
        return 0; 
    }

    int liberados_esq = freeAB(a->esq);
    int liberados_dir = freeAB(a->dir);


    free(a);

    return 1 + liberados_esq + liberados_dir;
}


//5 acho que é isto 


void caminho(ABin a) {
    if (a == NULL) {
        printf("Árvore vazia!\n");
        return;
    }

    while (a->pai != NULL) {
        if (a->pai->esq == a) {
            printf("esq\n");
        } else {
            printf("dir\n");
        }
        a = a->pai;
    }
}