#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>



void alfabetoparan(int n, char Exp[]) {
int j = strlen(Exp);
    
    for (int t = 0; t < j; t++) {
        char e = Exp[t];
        
        if ('a' <= e && e <= 'z') {
            e = 'a' + (e - 'a' + n) % 26;
        }
        else if ('A' <= e && e <= 'Z') {
            e = 'A' + (e - 'A' + n) % 26;
        }
        Exp[t] = e;

    }
}

int nelementos(char* O) {
    int z = 0;
    char alfabetomi[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char alfabetoma[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    for (int i = 0; i < 26; i++) {
        if (alfabetomi[i] == *O || alfabetoma[i] == *O) {
            z = i;
            break;
        }
    }
    return z;
}

float ocorrencias(char e, char Exp[]) {
    int z = 0;
    int j = strlen(Exp);
    if (e >= 'A' && e <= 'Z') {
        e += 'a' - 'A';
    }
    for (int i = 0; i < j; i++) {
        char exp_char = Exp[i];
        if (exp_char >= 'A' && exp_char <= 'Z') {
            exp_char += 'a' - 'A';
        }
        if (exp_char == e) {
            z += 1;
        }
    }
    return z;
}

int menoreposicao(double listadesomas[26]) {
    int t = 0;
    double min = listadesomas[0];
    for(int i=1; i<26; i++){
        if(min > listadesomas[i]){
            min = listadesomas[i];
            t = i;
        }
    }
    printf("%d ",t);
    return t;
}

char Exp[10000];
char Exp1[10000];
double listadesomas[26] = {0}; 
int main() { 
    if (scanf("%[^\n]", Exp)== 1){
    strcpy(Exp1,Exp);

    double soma = 0;
    double t = 0;

    for(int k = 0 ; k < 26; k++) {
        t = 0; 
        strcpy(Exp, Exp1);
        alfabetoparan(k, Exp);
        for (int i = 0; i < 26; i++) {
            float frequencia_relativa[26] = {43.31, 10.56, 23.13, 17.25, 56.88, 9.24, 12.59, 15.31, 38.45, 1.00, 5.61,
                                              27.98, 15.36, 33.92, 36.51, 16.14, 1.00, 38.64, 29.23, 35.43, 18.51, 5.13, 6.57, 1.48, 9.06, 1.39};

            char alfabetomi[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o',
             'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

            double E = frequencia_relativa[i];

            double O = (ocorrencias(alfabetomi[i], Exp));
            soma = (((E - O)*(E - O)) / E);
            t += soma;
        }
      
        listadesomas[k] = t;
    }
    }

      
    alfabetoparan(menoreposicao(listadesomas), Exp1);
    printf("%s\n", Exp1);
    
    return 0;
}