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

int ordenado (int v[], int N){
    
}
 