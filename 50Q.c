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
  int t ;
  int n=1, i = 0;
  float media = 0; 
  while(n != 0){
    scanf("%d" ,&n);
    media  += n;
    i ++ ; 
  }
  t = media / i ;
  return t ;
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

int bitsUm(unsigned int n) {
    int count = 0;
    while (n > 0) {
        if ( n %2 == 1) count++ ;
        n = n/2;
    }
    return count;
}

//5 

int trailingZ (unsigned int n){
      int  count=0;

      while(n!= 0){
        if (n%2==0){
          count++;
          n/2;
        }
      }
      return count;
}

//6 

int qDig (unsigned int n){
  int count = 0;
  while(n >0){
    count++;
    n/=10 ; 
    }
    return count;
}


//7 

char *firststrcat (char s1[], char s2[]){
  char s3[strlen(s1)+ strlen(s2)];
  int i;
  int j;
  
  for(i=0;i<sizeof(s1);i++){
    s3[i]=s1[i];
  }
  for(j=sizeof(s1);j<(sizeof(s2)+sizeof(s1)); j++){
    s3[j] = s2[j-sizeof(s1)] ;
  }
  s3[strlen(s1) + strlen(s2)] = '\0';
  return s3;
}

//8 

char *firststrcpy (char *dest, char source[]){
    int k;

    for (k = 0 ;k < sizeof(source) ; k++) {
      dest [k] = source [k] ;     
}
dest [k] = '\0' ;
return dest;
}

//9 

int firststrcmp (char s1[], char s2[]){
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

void firststrrev(char s[]){
    int i = strlen(s) - 1;
    int j;
    char s2[strlen(s)];

    for(j=0; j<strlen(s); j++){
        s2[j] = s[i];
        i--;
    }
    s2[j] = '\0';
    printf("%s\n", s2);
} 

//12 

void firststrnoV(char s[]) {
    int i;
    for (i = 0; i < strlen(s); i++) {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
            printf("");
        } else {
            printf("%c", s[i]);
        }
    }
}


//13 

void firsttruncW (char t[], int n){
    int i,j= 0 ;
    int k = 0;
    char e[strlen(t)];
    for (i = 0 ; i < strlen(t) ;i ++ ){
      if ((t[i]>='A' && t[i] <= 'Z'|| t[i]>='a' && t[i]<= 'z' )&& k < n){
          e[j] = t[i];  
          k++;
          j++;
      } 
    else if (t[i] == ' '){
      e[j] = t[i];
      k = 0 ; 
        j++;
    }
    else {
      k++;  
    }
    }
    printf("%s\n", e);
}


//14

char charMaisfreq (char s[]){
  int i,t ,k=0,maior = 0; 
  char maisfreq = s[k];
  for( k = 0 ; k < strlen(s) ;k++ ){
    t = 0;
  for (i = 0 ; i < (strlen(s)); i++ ){
        if (s[k] == s[i] ){
          t++;
        }
        if (s[0] == '\0'){
          return 0;
        }

if(t > maior){
    maior = t;
    maisfreq = s[k];
  }
  }
  }
  printf("%c", maisfreq);
  return maisfreq;
}

//15

int iguaisConsecutivos(char s[]){
    int maior = 0;
    int count = 0;
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

// 16

int difConsecutivos (char s[]){
    int maior = 0;
    int count = 0;
    int i=0;

    while(s[i]){
        while(s[i]!=s[i+1]){
            count++;
            i++;
            if (s[i] =='\0'){
              break;
            }
        }
        if(count >= maior)
            maior = count;
        count=1;
        i++;
    }

    printf("%d",maior);

    return maior;
}

//17 

int maiorPrefixo (char s1 [], char s2 []){
  int count = 0,i;
  for(i = 0;i< strlen(s1);i++){
    if(s1[i] == s2[i]){
      count++;
    }
    }
    return count;
}

//18 

int maiorSufixo (char s1 [], char s2 []){
  int count = 0,i;
  for(i = strlen(s1);i< 0;i--){
    if(s1[i] == s2[i]){
      count++;
    }
    }
    return count;
}


//19

int sufPref (char s1[], char s2[]){
int i , p = 0,count = 0;
  for (i = strlen(s1) ;i >0; i--){
    if(s1[i] == s2[p]){
      count++;
      p++;
    }
  }
  return count;
}

//20 

int contaPal (char s[]){
  int i,p = 1,r = strlen(s) ;
  for (i = 0 ; i < r ;i++ ){
    if (s[i]==' '){
        p++;
    }
  } 
  printf("%d", p);
}

//21 

int contaVogais (char s[]){
  int i ,p= 0;
  for (i = 0 ; i< strlen(s);i++){
    if (s[i] =='a'|| s[i] == 'e' || s[i] == 'i' || s[i] == 'o'|| s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'){
      p++;
    }
  }
  return p ;
  printf("%d" , p);
}

//22 

int contida (char a[], char b[]){
  int i ,e ,t = 0 ;
  for ( e = 0;e < strlen(a) ; e ++ ) {
  for(i = 0 ; i < strlen(b);i++){
    if (a[e] == b[i]){
      t++;
      break;
    }
  }
  }
  if (t == strlen(a)){
    printf("verdadeiro");

  }
  else {
    printf("falso");
  }
}

//23 

int palindorome (char s[]){
  int e ,i,t = 0;
  for (e = 0 ; e < strlen(s)/2;e++){
    for (i = strlen(s);i > strlen(s)/2;i--){
      if  (s[e] == s[i]){
      t++;
      break;
      }
  }
}
if (t == strlen(s)/2){
  printf("É palindorome");
}
else {
  printf("Não é palindorome");
}
}

//24 

int remRep(char x[]) {
    int i, j, len;

    if (x[0] == '\0') {
        return 0;
    }

    len = 1; 
    for (i = 1; x[i] != '\0'; i++) {
        if (x[i] != x[i - 1]) { //aaabaaabbbaaa  -> ababa
            x[len] = x[i];
            len++;
        }
    }
    x[len] = '\0';

    return len;
}

//25 

int limpaEspacos (char t[]){
  int i ,j = 0 ; 
  for (i = 1 ; i < strlen(t) ; i++ ) {  
     if (t [i] !=' ' ||t[i - 1] != ' ') { 
        t[j] = t[i];
        j++;
}
  }
  t[j] ='\0';
  return j;
}


//26  

int insere(int v[], int N, int x){
    int i, j;

    for(i=0; v[i]; i++){
        if(v[i] > x){
            for(j=N; j>i; j--){
                v[j] = v[j-1];    // vai mudar as posicoes dos elementos á frente do elemento da posicao i e inserir o novo elemento
            }
            v[i] = x;   
            break;
        }
        if(i == N - 1) {
            v[N] = x;
        }
    }
}

//27

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

//28 

int crescente(int a[], int i, int j) {
    int e;
    int g = abs(j - i); 

    for (e = i; e < j; e++) {
        if (a[e] > a[e + 1]) {
            return 0; 
        }
    }

    return 1; 
}


//29

int retiraNeg (int v[], int N){
  int p = 0 ;
  for (int i = 0 ; i < N;i++){
    if (v[i] < 0 ){
      for(int j = 0;j <N-1;j++){
        v[j]=v[j+1] ;
      }
      N-- ;
    }
  } 
  return N;
}


//30

int contaRepetidos(int numero, int v[], int N){
    int i=0, count=0;

    while(i<N){
        if(numero == v[i])
            count++;
        i++;
    }

    return count;
}

int menosFreq (int v[], int N){
  int i = 0,result = v[i];

  int menor = contaRepetidos(result,v,N);
    while (i<N) {
        int x = contaRepetidos(result,v,N);
        if (x <  menor) {
            menor = x;
            result =  v[i];
} 
i+=x;
    }
    return result;
}

//31 

int maisFreq (int v[], int N){
    int i=0, resultado = v[i];

    int maior = contaRepetidos(v[i], v, N);
    
    while(i<N){
        int x = contaRepetidos(v[i], v, N);
        if(x>maior){
            maior = x;
            resultado = v[i];
        }
        i+=x;
    }

    return resultado;
}


//32

int maxCresc(int v[], int N) {
    int i, count = 1, maior = 1;
    for (i = 0; i < N - 1; i++) {
        if (v[i + 1] >= v[i]) {
            count++;
        } else {
            if (count > maior) {
                maior = count;
            }
            count = 1;
        }
    }
    if (count > maior) {
        maior = count;
    }
    return maior;
}

//33 

int elimRep(int v[], int n) {
    int i, j, p = 0;
    for (i = 0; i < n; i++) {
        int repetido = 0;
        for (j = 0; j < p; j++) {
            if (v[i] == v[j]) {
                repetido = 1;
                break;
            }
        }
        if (repetido == 0) {
            v[p++] = v[i];
        }
    }
    return p; 
}

//34 

int elimRepOrd (int v[], int n){
  int i = 0;
  for (i = 0; i< n ;i++){
    if (v[i] == v[i+1]){
      v[i] = v[i+1];
      i+=1;
      printf("%d", v[i]);
    }
    else {
      printf("%d", v[i]);
  }
}
}


//35 

int comunsOrd (int a[], int na, int b[], int nb){
  int i ,o,count = 0;
  for (i = 0;  i <= na; i++) {
    for (o=0; o<=nb; o++) {
      if ((a[i]==b[o]) && (i==o)) {
        count++;
      }
    }
}
return count ;
}

//36 

int comuns (int a[], int na, int b[], int nb){
  int i,o,count = 0 ;
    for (i = 0;  i <= na; i++) {
    for (o=0; o<=nb; o++) {
      if (a[i]==b[o]) {
        count++;
    }
    }
    }
}

//37 

int minInd (int v[], int n){
  int i ,menor = 0 ;
  for (i = 0 ;i < n ;i++){
    if (v[i] <= v[menor]){
      menor= i ;
    }
  }
  return menor;
}

//38 

void somasAc1 (int v[], int Ac [], int N){
  int i ;
  Ac[0] = v[0];
  for (i = 1; i < N; i ++) {
    Ac [i] =Ac[i-1]+v[i];
}
}
//ou

int somaAc2(int v[], int indice){
    int i, resultado = 0;

    for(i=0; i<=indice; i++){
        resultado += v[i];
    }

    return resultado;
}

void somasAc2(int v[], int Ac[], int N){
    int i;

    for(i=0; i<N; i++){
        Ac[i] = somaAc2(v, i);
    }
}

//39 

int triSup(int N, float m[N][N]){
    int i, j, r = 1; //r representa a veracidade

    for(i=1; i<N; i++){
        for(j=0; j<i; j++){
            if(m[i][j] != 0)
                r = 0; //verdadeiro
        }
    }

    return r;
}

//40 

void transposta(int N, float m[N][N]) {
    int i, j, temp;

    for (i = 0; i < N; i++) {
        for (j = i + 1; j < N; j++) {
            temp = m[i][j];
            m[i][j] = m[j][i];
            m[j][i] = temp;
        }
    }
}

//41

void addTo (int N, int M, int a [N][M], int b[N][M]){
  assert(N == M);
  int i ,o; 
  for (i = 0; i<N ; ++i){
    for ( o = 0 ;o < N ; o++ ){
      a[i][o]+=b[i][o];
    }
  }
}

//42 

void unionSet(int N, int v1[N], int v2[N], int r[N]) {
    for (int i = 0; i < N; i++) {
        if (v1[i] || v2[i]) {
            r[i] = 1; 
        } else {
            r[i] = 0; 
        }
    }
}

//43 

int intersectSet (int N, int v1[N], int v2[N],int r[N]){
    for (int i = 0; i < N; i++) {
        if (v1[i] == v2[i]) {
            r[i] = 1; 
        } else {
            r[i] = 0; 
        }
    }
}

//44 

void joinArrays(int N, int array1[N], int array2[N], int result[2 * N]) {
    // Copia os elementos do primeiro array para o array resultante
    for (int i = 0; i < N; i++) {
        result[i] = array1[i];
    }

    // Copia os elementos do segundo array para o array resultante
    for (int i = 0; i < N; i++) {
        result[N + i] = array2[i];
    }
}

void intersectMSet(int N, int v1[N], int v2[N], int r[N]) {
    int t[2 * N];


    joinArrays(N, v1, v2, t);

    // Inicializa o array r com zeros
    for (int i = 0; i < N; i++) {
        r[i] = 0;
    }

    // Verifica quais elementos estão presentes na união e marca-os como presentes na interseção
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 2 * N; j++) {
            if (i == t[j]) {
                r[i] = 1;
                break; // Sai do loop interno se o elemento for encontrado
            }
        }
    }
}

//45 
int unionMSet (int N, int v1[N], int v2[N], int r[N]){
  int h[2*N];
  int j=0;

  for(int i=0; i < N; i++){
    h[j]=v1[i];
    h[j+1]=v2[i];
    j+=2;
  }

  for(int t=0; t < N; t++){
    for(int p = 0; p < 2*N; p++){
        if(t == h[p]){
            r[t]++;
        }
    }
  }

  for(int l=0; l < N; l++){
      printf("%d\n", r[l]);
  }
  return 0;
}
//??

//46 

//??

//47 

typedef enum movimento {Norte, Oeste, Sul, Este} Movimento;
typedef struct posicao {
int x, y;
} Posicao

Posicao posFinal (Posicao inicial, Movimento mov[], int N) {
    for (int i = 0; i<N; i++) {
        if (mov[i] == Norte) inicial.y++;
        if (mov[i] == Sul) inicial.y--;
        if (mov[i] == Este) inicial.x++;
        if (mov[i] == Oeste) inicial.x--;
    }
    return inicial;
}

//48 

int caminho (Posicao inicial, Posicao final, Movimento mov[], int N){
  for (int i = 0; i < N && inicial.x != final.x;i++){
    if (inicial.x < final.x){
      inicial.x++;
      mov[i] = Oeste;
    }
    else {
      inicial.x--;
      mov[i] = Este;
    }
  }
  for (int o = 0; o < N && inicial.y != final.y; o++){
    if ( inicial.y  < final.y ) {
      inicial.y++;
      mov[o]=Sul;
    }
    else{
      inicial.y--;
      mov[o]=Norte;
    }
  }
}

//49 

typedef struct posicao {
int x, y;
} Posicao;

int maisCentral (Posicao pos[], int N){
  int i ,indicedist = 0; 
  Posicao origem = {0 , 0};
  for(i= 0 ;i < N-1 ; i++) {
  //formula da distancia : sqrt((x2-x1)^2 + (y2-y1)^2)
   float dOrigem = sqrt( pow((pos[i].x -origem.x),2) + pow((pos[i].y -origem.y),2));
   float dOrigemMaior =sqrt( pow((pos[i+1].x -origem.x),2) + pow((pos[i+1].y -origem.y),2));
   if (dOrigem <= dOrigemMaior) {
    dOrigemMaior = dOrigem;
    indicedist = i;
    i+=1;
   }
  }
return indicedist;
}

//50 

typedef struct posicao {
int x, y;
} Posicao;

int vizinhos(Posicao p, Posicao pos[], int N){
    int i, count = 0;

    for(i=0; i<N; i++){
        if( sqrt(pow((p.x - pos[i].x),2) + pow((p.y- pos[i].y),2)) == 1 ){
            count++;
        }
    }
    return count;
}
