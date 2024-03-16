#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <assert.h>

double calculamantissa(char* Mant, int M) {
    double m = 0.0;
    for (int i = 0; i < M; i++) {
        if (Mant[i] == '1') {
            m += pow(2, -(i + 1));
        }
    }
    return m;
}

bool all_equal(char* tc, char c, int E) {
    for (int i = 0; i < E; ++i) {
        if (tc[i] != c) {
            return false;
        }
    }
    return true;
}

double expoente(char* Exp, int E){
    int k = pow(2, (E - 1)) - 1;
    int m = 0;
    for (int i = 0; i < E; ++i) {
        if (Exp[i] == '1') {
            m += pow(2, (E - 1 - i));
        }
    }
    double res = m - k;
    return res;
}

double calcula(char* Exp, char* Mant, int E, int M, char Sinal){
    if (all_equal(Exp, '0', E)) {
        if (all_equal(Mant, '0', M)) {
            if  (Sinal == '0') printf ("%lg\n", 0.0); 
            else  printf ("%lg\n", -0.0); 
        } else {
            double resultado = pow((-1), Sinal - '0') * calculamantissa (Mant, M) * pow(2,(1 + expoente(Exp, E))); //normalizados
            printf("%lg\n", resultado);
        }
    } else if (all_equal(Exp, '1', E)) {
        if (all_equal(Mant, '0', M)) {
            if  (Sinal == '0') printf ("+");
            else  printf("-");
            printf ("Infinity\n"); 
        } else {
            printf ("NaN\n"); 
        }
    } else {
        double result = pow((-1), Sinal - '0') * (1 + calculamantissa (Mant, M)) * pow(2, expoente(Exp, E)); //desnormalizados
        printf("%lg\n", result);
    }
    return 0;
}

int main() {
    int N;
    if (scanf("%d\n", &N) == 1) {
        char inputs[N][BUFSIZ];

        for (int i = 0; i < N; i++) {
            char buf[BUFSIZ];
            assert(fgets(buf, BUFSIZ, stdin) != NULL);
            assert(buf[strlen(buf) - 1] == '\n');
            buf[strlen(buf) - 1] = 0;
            strcpy(inputs[i], buf);
        }

        for (int i = 0; i < N; i++) {
            int E, M;
            char bits[BUFSIZ] = {0};
            char Sinal;
            char Exp[BUFSIZ] = {0};
            char Mant[BUFSIZ] = {0};
            char formato[BUFSIZ];

            sscanf(inputs[i], "%d %d %s", &E, &M, bits);
            sprintf(formato, "%%c%%%ds%%%ds", E, M);
            sscanf(bits, formato, &Sinal, Exp, Mant);

            calcula (Exp, Mant, E, M, Sinal);
        }
    }
      
    return 0;
}
