#include <stdio.h> 

void main (){
  int i ;
  for( i = 0 ; i <9; i++)
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
/*
    #
  #####
 #######
 #######
#########
 #######
 #######
  #####
    # 
*/
