#include <stdio.h>


//1 Funções sobre strings
//1 

int contaVogais(char *s) {
    int count = 0;
    char c;
    while (*s != '\0') {
        c = *s;
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            count++;
        }

        s++;
    }
    printf("%d",count);
    return count;
}


//2 

void retiraVogaisRep(char *s) {
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
    printf("%s\n", t);
}

//3

void duplicaVogais(char *s) {
    char t[strlen(s) * 2 + 1]; 
    int i, p = 0;
    for (i = 0; i < strlen(s); i++) {
        if ((s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ||
             s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') &&
            (s[i] != s[i + 1])) {
            t[p] = s[i];
            t[p + 1] = s[i];
            
            p += 2;
        } else {
            t[p] = s[i];
            p++;
        }
    }
    t[p] = '\0'; 
    printf("%s\n", t);
}

//2 Arrays ordenados

//1 

int ordenado(int v[], int N) {
    for (int i = 0; i < N - 1; i++) {
        if (v[i] > v[i + 1]) {
            return 1; 
        }
    }
    return 0; 
}

 
//2

void merge(int r[], int a[], int b[], int na, int nb) {
    int i = 0, j = 0, k = 0;

    while (i < na && j < nb) {
        if (a[i] <= b[j]) {
            r[k++] = a[i++];
        } else {
            r[k++] = b[j++];
        }
    }

    while (i < na) {
        r[k++] = a[i++];
    }

    while (j < nb) {
        r[k++] = b[j++];
    }
}

//3

int partition_aux(int v[], int aux[], int N, int x) {
    int i, j;
    int count = 0;

    for (i = 0; i < N; i++) {
        if (v[i] <= x) {
            aux[count++] = v[i];
        }
    }

    for (i = 0; i < N; i++) {
        if (v[i] > x) {
            aux[count++] = v[i];
        }
    }

    for (i = 0; i < N; i++) {
        v[i] = aux[i];
    }

    return count;
}

int partition(int v[], int N, int x) {
    int aux[N];
    return partition_aux(v, aux, N, x);
}

//versao alternativa sem uso de uma array auxiliar 

int partition1(int v[], int N, int x) {
    int a = 0; 
    int b = N - 1; 

    while (a <= b) {
        if (v[a] <= x) {
            a++;
        } else if (v[b] > x) {
            b--;
        } else {
            int temp = v[a];
            v[a] = v[b];
            v[b] = temp;
            a++;
            b--;
        }
    }

    return a;
}


