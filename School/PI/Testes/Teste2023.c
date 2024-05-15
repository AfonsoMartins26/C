#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


//Teste 2023

//1

int perfeito(int x){
  int soma = 0;
  for(int i = 0; i < x ; i++){
    if ( i % x == 0) {
      soma += i;

    }
      if (soma == x){
      return 1;
      }
  }
  return 0 ;
}


//2

typedef struct {
int x,y;
} Ponto;

int distanciaorigem( Ponto p){
  return sqrt(p.x * p.x + p.y*p.y);
}

void ordena(Ponto pos[], int N){
  int distancias[N+1];
  for (int i = 0;i <N ;i++){
    distancias[i] = distanciaorigem(pos[i]);
  }

    ordenaaux(distancias, pos, N);
}

void ordenaaux(double distancias[], Ponto pos[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        for (int j = i + 1; j < tamanho; j++) {
            if (distancias[i] > distancias[j]) {

                double temp_dist = distancias[i];
                distancias[i] = distancias[j];
                distancias[j] = temp_dist;

                Ponto temp_ponto = pos[i];
                pos[i] = pos[j];
                pos[j] = temp_ponto;
            }
        }
    }
}


//3


typedef struct abin_nodo {
int valor;
struct abin_nodo *esq, *dir;
} *ABin;


int depth(ABin a, int x){
  depthaux(a,x,0);
}

int depthaux(ABin a, int x,int nivel){

  if (a == NULL){
    return -1;
  }
  
  if(a->valor == x){
    return nivel;
  }

  else{
    int esq = depthaux(a->esq,x,nivel+1);
    int dir = depthaux(a->dir,x,nivel+1);

    if (esq != -1 && dir != -1){
      if (esq < dir){
        return esq;
      }
      else{
        return dir;
      }
    }

    if (esq != -1){
      return esq;
    }
    else{
      return dir;
    }
  }
}


//4

int wordle(char secreta[], char tentativa[]) {
    int count = 0;
    int l = strlen(secreta);
    
    for (int i = 0; i < l; i++) {
        if (secreta[i] == tentativa[i]) {
            count++;
            tentativa[i] = toupper(tentativa[i]);
        } else {
            int found = 0;
            for (int j = 0; j < l; j++) {
                if (secreta[j] == tentativa[i] && secreta[j] != tentativa[j]) {
                    tentativa[i] = tolower(tentativa[i]);
                    found = 1;
                    break;
                }
            }
            if (!found) {
                tentativa[i] = '*';
            }
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