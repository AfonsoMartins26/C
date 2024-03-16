#include <stdio.h>

//1 

/*
(a)
int x [15] = {1, 2, 3, 4, 5,
6, 7, 8, 9,10,
11,12,13,14,15};
int *y, *z, i;
y = x; z = x+3;
for (i=0; (i<5); i++) {
printf ("%d %d %d\n",
x[i], *y, *z);
y = y+1; z = z+2;
}



1 1 4
2 2 6
3 3 8
4 4 10
5 5 12
*/


/*
(b) 
int main () {
int i, j, *a, *b;
i=3; j=5;
a = &i; b = &j;
i++;
j = i + *b;
b = a;
j = j + *b;
printf ("%d\n", j);
return 0;
}

13 
*/


// 2
void swapM (int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int x = 3 ; 
    int y = 5 ; 
    swapM(&x ,&y);
    printf ("%d %d\n", x ,y);
}


// 3 

void swap (int v[], int i, int j){
  int t = v[i];
  v[i]=v[j];
  v[j]= t ; 
}

// 4 
int soma (int v[], int N){
    int sum = 0 ; 
    for ( int i = 0 ; i <N;i++){
      sum  += v [i] ;  
    }
    return sum ;
 }

 // 5 
int maximum (int v[], int N, int *m){
  if (N<1) return 1 ;
  else {
    *m = v[0];
  for (int i = 0 ; i < N ;i++ ){
    if (v[i] > *m ) {
      *m = v[i];
    }
  }
return 0 ;
  }
}

//6 
void quadrados (int q[], int N){
  for (int i = 1; i < (N+1) ; i++ ){
    q[i] = i^2 ;
  }
}

//7 
void pascal (int v[], int N){
  if (N == 1) v[0] = 1 ; 
  else{
    int prev [N - 1];
    pascal ( prev , N-1);
    v[0] = 1;
    v[N-1] = 1 ;
    for (int i =1 ; i < N-1 ; i ++  ){
      v[i] = prev[ i-1] + prev [i];
    }
  }
}

