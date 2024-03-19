#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

//1 

int prim(){
    int n,max=0;
    while(n > 0){
        assert(scanf("%d", &n)==1);
        if (n >= max)
            max = n;
    }
    return max;
}

//2 

int sec(){
  int t,i =0 ,n;
  float media;
  while(n != 0){
    scanf("%d", &n);
    media +=n ;
    i++;
  }
  t = media/i;
  return t;
}

//3

int three(){
  int n , max = 0,max2 = 0; 
  while(n != 0){
    scanf("%d" ,&n);
    if ( n>= max){
      max2 = max ; 
      max = n;
    }
    else if (n >=max2){
      max2 = n;
    }
  }
  return max2 ; 
}

//4 

int bitsUm (unsigned int n){
  int count ; 
  while (n >0){
    if(n %2 == 1){
      count++;
      n/2;
    }
  }
  return count;
}

//5

int trailingZ (unsigned int n){
  int count ; 
  while (n >0){
    if(n %2 == 0){
      count++;
      n/2;
    }
  }
  return count;
}

//6

int qDig (unsigned int n){
  int count = 0 ;
  while (n > 0){
    count++;
    n/10;
  }
  return count ;
}

//7 
char *strcat (char s1[], char s2[]){
  char s3[strlen(s1)+strlen(s2)]; 
  int i, o;
  for (i = 0 ;i  < strlen(s1) ; i++) {
    s3[i] = s1[i];
}
for (o = 0 ;o <strlen(s2), o++){
  s3[i+o]=s2[i];
}
s3[strlen(s1)+strlen(s2)] = '\0';
return s3;
}

//8

char *fststrcopy (char *dest, char source[]){
  int i ; 
  for ( i  =0 ;i < strlen(source); i++ ) {
    *(dest+i) = source[i];
  }
  *(dest+strlen(source)) = '\0';
  return dest;
}

//9

int strcmp (char s1[], char s2[]){
    int j;
    int y = 0;
    for (j = 0 ;j <strlen(s2);j++){
      if (s1[j] == s2[j]){
        y++ ;
        if ( y == strlen(s2) ){
          return 0;
        }
      }
      else if (s1[j] < s2[j]){
        return -1;
    }
    else if (s1[j] > s2[j]){
      return 1;
    }
    }
    
}

//10

char *firststrstr(char s1[], char s2[]){ 
    if(*s1 == '\0' && *s2 == '\0') 
		return s1;

	for( ; *s1 ; s1++ ){ 
		if(*s1 == *s2){
			char *r = s1;
			char *p = s2;
			while(*s1 == *p && *s1){
				p++;
				s1++;
			}
			if(*p == '\0')
				return r;	
		}
	}
	return NULL;
}

//11

void strrev (char s[]){
  int i  ;
  int j = strlen(s) - 1; 
  char s2[strlen(s)];
  for ( i = 0 ;i < strlen(s);i ++){
    s2[j] = s[i];
    j--;
}
s2[j+1] = '\0';
printf("%s\n", s2);
}

//12

void strnoV (char s[]){
  int i; 
  for ( i = 0 ; i < strlen(s); i++){
    if ( s[i] =='a'|| s[i] =='e' || s[i] =='i'|| s[i] =='o'|| s[i] =='u'|| s[i] =='A'|| s[i] =='E'|| s[i] =='I'|| s[i] =='O'|| s[i] =='U'){
      printf("");
    }
    else{
      printf("%c", s[i]);
    }
}
}

//13 

void truncW(char t[], int N){
    int i, j = 0, n=0;

    for(i=0; t[i]; i++){
        if(t[i] == ' '){
            n = 0;
            t[j] = t[i];
            j++;
        } else {
            if (n < N){
                t[j] = t[i];
                j++;
                n++;
            }
        }
    }
    t[j] = '\0';
}

//14 
char charMaisfreq(char s[]){
    int i=0, maior = 0, count, j;
    char maisFreq = s[i];
    
    for(i=0; s[i]; i++){
        count = 0;
        for(j=0; s[j]; j++){
            if (s[i] == s[j])
                count++;
            }
        if(count > maior){
            maior = count;
            maisFreq = s[i];
        }
    }

    printf("%c", maisFreq);

    return maisFreq;
}



//15  
int iguaisConsecutivos(char s[]){
    int maior = 0;
    int count = 1;
    int i=0;

    while(s[i]){
        while(s[i]==s[i+1]){
            count++;
            i++;
        }
        if(count >= maior)
            maior = count;
        count=1;
        i++;
    }

    printf("%d",maior);

    return maior;
}

//30 
int charfrequente (int v[],int N,int c){
  int i, count;
  for(i = 0 ;i < N ; i++){
     if(v[i] == c){
      count++;
     }
  }
  return count;
}

int menosFreq (int v[], int N){
    int i ,resultado = v[i];
    int x = charfrequente(v,N,resultado);
    for(i = 0 ; i < N ; i++ ){
      int t = charfrequente(v,N,resultado);
      if(x<t ){
        x = t;
        resultado = v[i];
      }
}
return resultado;
}


//31

int maisFreq (int v[], int N){
      int i ,resultado = v[i];
    int x = charfrequente(v,N,resultado);
    for(i = 0 ; i < N ; i++ ){
      int t = charfrequente(v,N,resultado);
      if(t >x ){
        x = t;
        resultado = v[i];
      }
}
return resultado;
}