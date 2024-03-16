#include <stdio.h>
#include <math.h>

int maiorSufixo (char s1 [], char s2 []){
  int count = 0,i;
  for(i = strlen(s1);i< 0;i--){
    if(s1[i] == s2[i]){
      count++;
    }
    }
    return count;
}   

int main() {
    char texto[] = "Helllo,fasafagsega";
    char texto2[] = "Helega";
    int i = maiorSufixo(texto,texto2);
    return 0;
}

