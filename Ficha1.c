#include <stdio.h>
//1 Estado e atribuições 

//1.
/*
  12
  16
*/ 

//2 
// codigo não compila pois y não têm um valor 

// 3
/*
  A 65 
  B 66 2 50 
  b 98 
*/

//4
/*
  100 200 
*/


//2 Estruturas de controlo

//(a) 
/*
  3 5 
*/

//(b)
/*
  11 66
  x vai ser 11 sendo que while inicia um loop e acaba com x = 11 e y vai ser a adicao de todos os valoreas de x até 11 ao valor de y já predefenido 
  ou seja  x =11 e y = 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10 + 11 = 66  
  y += x é a mesma coisa que y = y + x 
*/

//(c)
/*
_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#
verifica se o resto da divisao de i com 2 == 0 vai meter `_` e se for o resto da divisao for diferente de 0 mete `#` até que i chege a 19 sendo que 
têm de ser menor do que 20 e que vai ser adicionado 1  a cada interacao */

//(d)
/*
  1
  01
  11
  001
  101
  011
  111
  0001
  1001
  0101
  1101
  0011
  1011
  0111
  1111
*/

//3 Programas iterativos 

//1 

void main() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++)
            printf("#");
        printf("\n");
    }
}

//2

void main(){
    for (int i = 0; i < 5; i++) {
        if (i == 0 || i == 2 || i == 4){ 
        for (int j = 0; j < 5; j++){
          if (j%2 == 0) putchar ('#');
          else putchar('_');
        }
        }
        else{ 
        for (int j = 0; j < 5; j++){
        if (j%2 == 0) putchar ('_');
        else putchar('#');
        }
        }
      printf("\n");
    }
}

// 3 
void triang1(int n) {
    for(int i = 1; i < 2 * n; i++) {
        for(int j = 1; j <= 2 * n - i; j++) {
            if(j <= i) putchar('#');
        }
        putchar('\n');
    }
}

void  triang2 (int n) {
    int i, j, k;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n - i; j++)
            printf(" ");
        for (k = 1; k <= 2 * i - 1; k++)
            printf("#");
        printf("\n");
    }
}

int main(int argc, char const *argv[])
{
    triang1(5);
    triang2(5);
    return 0;
}

//4 
void main (){
  for(int i = 0 ; i <9; i++)
    if (i == 4) printf ("#");
    else      printf(" ");
  printf("\n");

  for(int k = 0 ; k<9;k++)  
  if(k < 2) printf(" ");
  else if (k>6) printf(" ");
else        printf("#");
  printf("\n");
  for (int w = 0 ;w<2;w++){
    for(int a = 0;a <9;a++)
    if (a == 0)printf(" ");
    else if (a == 8) printf(" ");
    else printf("#");
    printf( "\n" );
  }
  for(int e = 0 ;e< 10;e++ )
  printf("#");
printf("\n");
  for (int w = 0 ;w<2;w++){
    for(int a = 0;a <9;a++)
    if (a == 0)printf(" ");
    else if (a == 8) printf(" ");
    else printf("#");
    printf( "\n" );
  }
  for(int k = 0 ; k<9;k++)  
  if(k < 2) printf(" ");
  else if (k>6) printf(" ");
else        printf("#");
  printf("\n"); 

  for(int i = 0 ; i <9; i++)
    if (i == 4) printf ("#");
    else      printf(" ");
  printf("\n");
}