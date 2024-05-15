#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


//Teste 2023

//1

int perfeito(int x) {
    int soma = 0;

    for (int i = 1; i <= x / 2; i++) {
        if (x % i == 0) {
            soma += i; 
        }
        
        if (soma == x){
          return 1;
        }
    }

    return 0;
}

//2

typedef struct {
int x,y;
} Ponto;

double distancia_origem(Ponto p) {
    return sqrt(p.x * p.x + p.y * p.y);
}

int compara(const void *p1, const void *p2) {
    Ponto *pt1 = (Ponto *) p1;
    Ponto *pt2 = (Ponto *) p2;

    double dist1 = distancia_origem(*pt1);
    double dist2 = distancia_origem(*pt2);

    if (dist1 < dist2) {
        return -1;
    } else if (dist1 > dist2) {
        return 1;
    } else {
        return 0;
    }
}

void ordena(Ponto pos[], int N) {
    qsort(pos, N, sizeof(Ponto), compara);
}

//3

typedef struct abin_nodo {
int valor;
struct abin_nodo *esq, *dir;
} *ABin;

int depthaux(ABin a, int x, int nivel) {
  if (a == NULL ) return -1;

  if (a->valor == x) return nivel;

    int nivelesq = depthaux(a->esq,x, nivel+1);
    int niveldir = depthaux(a->dir,x, nivel+1);

    if (nivelesq != NULL && niveldir != NULL){
        if (nivelesq < niveldir){
            return nivelesq;
        }
        else {
            return niveldir;
        }
    }
    if (nivelesq != -1){
      return nivelesq;
    }
    else {
      return niveldir;
    }
}

int depth(Abin a, int x){
    return depthaux(a,x,0);
}


//4 errada 


int wordle(char secreta[], char tentativa[]) {
    int count = 0;
    int tam = strlen(secreta);

    for(int j = 0; j < tam ; j++) {
        int acertou = 0;
        for (int i = 0; i < tam; i++) {
            if (secreta[i] == tentativa[j]) {
                if (i == j) {
                    count++;
                    tentativa[j] = toupper(secreta[j]); // Converte para maiúscula
                    acertou = 1;
                    break;
                } else {
                    acertou = 1;
                    tentativa[j] = secreta[i];
                }
            } 
        }
        if (!acertou) {
            tentativa[j] = '*'; // Substitui por '*'
        }
    }

    return count;
}

//5


typedef struct lint_nodo {
    int valor;
    struct lint_nodo *prox;
} *LInt;


LInt novoNo(int val) {
    LInt novo = (LInt)malloc(sizeof(struct lint_nodo));
    novo->valor = val;
    novo->prox = NULL;
    return novo;
}

LInt periodica(char s[]) {
    LInt inicio = NULL;
    LInt atual = NULL;

    int len = strlen(s);
    int i = 0;

    while (s[i] != '(' && s[i] != '\0') {
        if (s[i] >= '0' && s[i] <= '9') {
            if (inicio == NULL) {
                inicio = novoNo(s[i] - '0');
                atual = inicio;
            } else {
                atual->prox = novoNo(s[i] - '0');
                atual = atual->prox;
            }
        }
        i++;
    }


    if (s[i] == '(') {
        LInt partePer = NULL;
        LInt atualPer = NULL;

        i++;
        while (s[i] != ')' && s[i] != '\0') {
            if (s[i] >= '0' && s[i] <= '9') {
                if (partePer == NULL) {
                    partePer = novoNo(s[i] - '0');
                    atualPer = partePer;
                } else {
                    atualPer->prox = novoNo(s[i] - '0');
                    atualPer = atualPer->prox;
                }
            }
            i++;
        }

        if (inicio != NULL && atual != NULL && partePer != NULL) {
            atual->prox = partePer;
            atualPer->prox = partePer;
        }
    }

    return inicio;
}