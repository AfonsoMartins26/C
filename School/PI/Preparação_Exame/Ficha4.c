#include <stdio.h>
#include <string.h>

// 1 Funcoes sobre strings 

// 1

int contaVogais(char *s) {
    int count = 0, i;
    char c;
    int tamanho = strlen(s);
    for (i = 0 ;i <tamanho+1 ; i++) {
        c = s[i];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            count++;
        }

    }
    return count;
}

// 2

int retiraVogaisRep(char *s) {
    char t[strlen(s) + 1]; 
    int i, p = 0;
    for (i = 0; i < strlen(s); i++) {
        if ((s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ||
             s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') &&
            (s[i] != s[i + 1])) {
            t[p] = s[i];
            p++;
        }
        else if (s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u' &&
                 s[i] != 'A' && s[i] != 'E' && s[i] != 'I' && s[i] != 'O' && s[i] != 'U') {
            t[p] = s[i];
            p++;
        }
    }
    t[p] = '\0';
    int vogais_retiradas= contaVogais(s)-contaVogais(t);
    strcpy(s,t);
    return vogais_retiradas;
}

// 3

int duplicaVogais (char *s){
    char t[strlen(s) + 1]; 
    int i, p = 0;
    for (i = 0; i < strlen(s); i++) {
        if ((s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ||
             s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') &&
            (s[i] != s[i + 1])) {
            t[p] = s[i];
            t[p+1] = s[i];
            p+=2;
        }
        else if (s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u' &&
                 s[i] != 'A' && s[i] != 'E' && s[i] != 'I' && s[i] != 'O' && s[i] != 'U') {
            t[p] = s[i];
            p++;
        }
    }
    t[p] = '\0';
    int vogais_acrescentadas= contaVogais(t)-contaVogais(s);
    strcpy(s,t);
    return vogais_acrescentadas;
}

// 2 Arrays Ordenados 

// 1

int ordenado (int a[], int N){
    int i ;
    for (i = 0; i < N; i++){
        if (a[i] > a[i+1]){
            return 1;
        }
    }
    return 0;
}

//2

void merge (int a[], int na, int b[], int nb, int r[]){
    int i,j = 0,p = 0;
    for (i = 0 ; i< (na+nb) ; i++){
        if (a[j] < b[p]){
            r[i] = a[j];
            j++;
        }
        else{
            r[i] = b[p];
            p++;
        }
    }
}

//3

int partition_aux(int v[], int N, int x) {
    int aux[N];
    int count = 0;
    int i;

    for (i = 0; i < N; i++) {
        if (v[i] <= x) {
            aux[count] = v[i];
            count++;
        }
    }

    for (i = 0; i < N; i++) {
        if (v[i] > x) {
            aux[count] = v[i];
            count++;
        }
    }

    for (i = 0; i < N; i++) {
        v[i] = aux[i];
    }

    return count;
}

int partition(int v[], int N, int x) {
    int a = 0;
    int b;

    for (b = 0; b < N; b++) {
        if (v[b] <= x) {
            int temp = v[a];
            v[a] = v[b];
            v[b] = temp;
            a++;
        }
    }

    return a;
}