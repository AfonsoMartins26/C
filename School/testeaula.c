#include <stdio.h>


int max(int a, int b) {	
if (a > b) {	
int r;	
r = a;
return r;	
} else {	
int m;	
m = b;	
return m;	
}	
}


int fact(int n) {	
int r, i;	
r = i = 1;	
while (i <= n) {	
r *= i;	
i++;	
}	
return r;	
}


int main () {
  printf("Enter two numbers:  \n");
  int n1, n2;
  scanf("%d %d", &n1, &n2);
  int r =max(n1, n2);
  printf( "The maximum number is %d.\n", r );
}
