#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//Exame 2023 

//1 

int fib(int n) {
    if (n < 0) {
        return -1; 
    }
    else if (n < 2) {
        return n; 
    }
    else {
        return fib(n - 1) + fib(n - 2);
    }
}

int isFib(int x){
    int i = 0;
    int fib_i;

    while ((fib_i = fib(i)) <= x) {
        if (fib_i == x){
            return 1; 
        }
        i++;
    }
    return 0; 
}

//2

typedef struct {
float teste, minis;
} Aluno;

int moda(Aluno turma[], int N) {
    float notas_finais[N];
    int frequencia[21] = {0};

    for (int i = 0; i < N; i++) {
        float nota_final = 0.8 * turma[i].teste + 0.2 * turma[i].minis;
        nota_final = ((int)(nota_final * 10 + 0.5)) / 10.0;
        notas_finais[i] = nota_final;
    }

    for (int i = 0; i < N; i++) {
        if (notas_finais[i] < 9.5) {
            continue;
        }
        frequencia[(int)notas_finais[i]]++;
    }

    int max_frequencia = 0;
    int moda_nota = -1;
    for (int i = 0; i <= 20; i++) {
        if (frequencia[i] > max_frequencia) {
            max_frequencia = frequencia[i];
            moda_nota = i;
        }
    }

    if (moda_nota == -1) {
        return 0;
    }

    return moda_nota;
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

int isspace(int c) {
    return (c == ' ' || c == '\t' || c == '\n');
}


int verifica(char frase[], int k) {
    int i = 0;
    int palavra_len = 0;
    int todas_maior_k = 1; 

    while (frase[i] != '\0') {
        while (frase[i] != '\0' && isspace(frase[i]))
            i++;

        
        palavra_len = 0;
        while (frase[i] != '\0' && !isspace(frase[i])) {
            palavra_len++;
            i++;
        }

        if (palavra_len < k) {
            todas_maior_k = 0;
            break; 
        }
    }

    return todas_maior_k;
}

//5 não tenho acerteza se está bem


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