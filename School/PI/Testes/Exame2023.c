#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//Exame 2023 

//1 

int fib(int n){
  if (n < 0){
    return -1;
  }

  if (n < 2){
    return n;
  }

  else{
    return fib(n-1) + fib(n-2);
  }
}
int isFib(int x){
  for (int i = 0 ; i< x ; i++){
    if ( fib(i) == x) {
      return 1;
    }
  }
  return 0 ;
}


//2

typedef struct {
float teste, minis;
} Aluno;

int nota(aluno a){
  int final ;
  final = a.teste *0.8 + a.minis * 0.20;
}

int frequencia(int notas[], int N) {
    if (N <= 0) {
        return -1; 
    }

    int max_valor = notas[0];
    for (int i = 1; i < N; i++) {
        if (notas[i] > max_valor) {
            max_valor = notas[i];
        }
    }

    int *frequencias = (int*)calloc(max_valor + 1, sizeof(int));

    for (int i = 0; i < N; i++) {
        frequencias[notas[i]]++;
    }

    int max_frequencia = 0;
    int elemento_max_frequencia = -1;
    for (int i = 0; i <= max_valor; i++) {
        if (frequencias[i] > max_frequencia) {
            max_frequencia = frequencias[i];
            elemento_max_frequencia = i;
        }
    }

    free(frequencias);

    return elemento_max_frequencia;
}

int moda(Aluno turma[], int N){
  int notas[N];
  for (int i = 0; i< N ;i++){
    notas[i] =nota(turma[i]);
  }

  return frequencia(notas,N);
}

//3

typedef struct lint_nodo {
int valor;
struct lint_nodo *prox;
} *LInt;


int take(int n, LInt *l) {
    if (*l == NULL || n <= 0) 
        return 0;

    int count = 0;
    LInt current = *l;
    LInt prev = NULL;

    
    while (current != NULL && n > 1) {
        prev = current;
        current = current->prox;
        n--;
    }

    if (current == NULL)
        return 0;

    
    while (current != NULL) {
        LInt temp = current;
        current = current->prox;
        free(temp);
        count++;
    }

    
    if (prev != NULL)
        prev->prox = NULL;
    else
        *l = NULL; 

    return count;
}


//4

int isspace(char x){
  if (x == ' ' || x == '\t' || x == '\n') return 1;
  else {
    return 0;
  }
}

int verifica(char frase[], int k){
  int i = 0,count = 0,todasmaiores = 1;
    while (frase[i] != '\0') {
        while (frase[i] != '\0' && isspace(frase[i]))
            i++;

        
        count = 0;
        while (frase[i] != '\0' && !isspace(frase[i])) {
            count++;
            i++;
        }

        if(count < k){
          todasmaiores = 0;
          break;
        }
    }
  return todasmaiores;
}


//5

typedef struct abin_nodo {
int valor;
struct abin_nodo *esq, *dir;
} *ABin;


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