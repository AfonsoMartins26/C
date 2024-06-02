#include <stdio.h>
#include <math.h>

typedef struct aluno {
int numero;
char nome[100];
int miniT [6];
float teste;
} Aluno;

//1

int nota (Aluno a){
  int i ; 
  float allnotasmini = 0;
  float notamini =0  ;
  for ( i = 0 ;i <  6; i++){
    allnotasmini += a.miniT[i];
    notamini = (allnotasmini/6.0)*0.20;
}
    float nota = notamini +(a.teste * 0.80);
    if (nota >9.5){
        return round(nota);
      return 1;
    }
    else{
      return 0;
    }
}

//2 

int procuraNum (int num, Aluno t[], int N){
    int i ;
    for (i = 0 ;i < N ;i++){
      if (t[i].numero == num){
          return i;
          }
    }
    return -1;
}

//3

void ordenaPorNum(Aluno t[], int N) {
    int i, j;
    Aluno temp;

    for (i = 0; i < N - 1; i++) {
        for (j = 0; j < N - i - 1; j++) {
            if (t[j].numero > t[j + 1].numero) {
                temp = t[j];
                t[j] = t[j + 1];
                t[j + 1] = temp;
            }
        }
    }
}


//4

void criaIndPorNum(Aluno t[], int N, int ind[]) {
    int i,j,temp;
    for ( i = 0; i < N; i++) {
        ind[i] = i;
    }

    for ( i = 0; i < N - 1; i++) {
        for ( j = 0; j < N - i - 1; j++) {
            if (t[ind[j]].numero > t[ind[j + 1]].numero) {
                temp = ind[j];
                ind[j] = ind[j + 1];
                ind[j + 1] = temp;
            }
        }
    }
}


//5 

void imprimeTurma(int ind[], Aluno t[], int N) {
    printf("Números, nomes e notas dos alunos por ordem crescente do número de aluno:\n");
    for (int i = 0; i < N; i++) {
        printf("Número: %d, Nome: %s, Notas:", t[ind[i]].numero, t[ind[i]].nome);
        for (int j = 0; j < 6; j++) {
            printf(" %d", t[ind[i]].miniT[j]);
        }
        printf(", Teste: %.2f\n", t[ind[i]].teste);
    }
} 

//6 

int procuraNum2(Aluno t [], int N, int ind[],int num){
    int left = 0;
    int right = N - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (t[mid].numero == num) {
            return mid;
        } else if (t[mid].numero < num) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

//7

void criaIndPorNome(Aluno t[], int N, int ind[]) {
    int i, j, temp;
    for (i = 0; i < N; i++) {
        ind[i] = i;
    }

    for (i = 0; i < N - 1; i++) {
        for (j = 0; j < N - i - 1; j++) {
            if (strcmp(t[ind[j]].nome, t[ind[j + 1]].nome) > 0) { //strcmp > 0 quando a primeira string é "maior" que a segunda
                temp = ind[j];
                ind[j] = ind[j + 1];
                ind[j + 1] = temp;
            }
        }
    }
}