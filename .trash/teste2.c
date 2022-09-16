#include<stdio.h>
#include<stdlib.h>
#include"tp1.h"


FILE *openFile(char *file){
  
  FILE *arq;
  arq = fopen(file,"r");
  
  return arq;
}

/*FILE *openFile(char **file){
  
  FILE *arq;

  arq = fopen(file[2],"r");

  return arq;
}*/

int **alocaMatriz(int rows, int cols){

  int **x;

  //Alcoa as colunas 
  x = malloc(rows * sizeof * x);

  //Aloca as linhas 
  for (int i=0; i<rows; i++){
    x[i] = malloc(cols * sizeof *x[i]);
  }
  return x;
}

void desalocaMatriz(int **matriz, int rows){

  for (int i=0; i<rows; i++){
    free(matriz[i]);
  }
  free(matriz);
}

int **montaTabuleiro(FILE *arq, int **matriz, int rows, int cols){

  int j,a;

  for(int i = 0; i<rows; i++){

    if((i%2) == 0){
      j=0;      
    }else{      
      j=1;
    }

    while(j<cols){

      fscanf(arq, "%d", &a);
      matriz[i][j]= a;
      //printf ("montando: %d \n", a); // coloquei aqui um printf
      j=j+2;
    }
  }
  return matriz;
}
void imprimeMatriz(int **matriz, int rows, int cols){

  int j;

  for(int i = 0; i<rows; i++){

    if((i%2)==0){
      j=0;
    }else{
      j= 1;
      printf(" ");
    }

    while(j<cols){

      printf(" %d ",matriz[i][j]);
      j = j+2;
    }
    printf("\n");
  }
}
int *quantidade(int **matriz,int rows, int cols){

  int j=0,a=0,*posi,b=0;

  posi = malloc( sizeof(int) *200);
    
  for(int i=0; i<rows; i++){
    if(i%2 == 0){
      j=0;
    }else{
      j=1;
    }

    for(; j<cols; j=j+2){
      if(matriz[i][j] == 1){
        
        b= 2*a;

        posi[b] = i;
        b++;

        posi[b] = j;
        
        a++;
        posi[200] = a;
      }
    }
  }
  return posi;
}
void jogadas(int **matriz, int i, int j,int n, int m){

  diagonals(matriz, i++, j--, n, m);
  diagonals(matriz, i++, j++, n, m);  
  diagonals(matriz, i--, j--, n, m);
  diagonals(matriz, i--, j++, n, m);
  
}

void diagonals(int **matriz,int i, int j, int n, int m){

  if ( i >= 0 && j >= 0 && i < n && j < m){
    if (matriz[i][j] == 2 ){
      printf("encontrou o 2 \n");

      i++, j--;

      if ( i >= 0 && j >= 0 && i < n && j< m){
        if ( matriz [i][j] == 0 ){
          printf("encontrou o 0 \n");
  
          matriz [i][j] = 1;

          i--, j++;
          matriz [i][j] = 0;

          i--, j++;
          matriz [i][j] = 0;

          i++, j--;
          i++, j--;

          jogadas(matriz, i, j, n, m);

        }
      }else{
        i--, j++;
        matriz[i][j] = 2;
      }
    }
  }
  else{
    i--, j++;
    matriz[i][j] = 1;
  }
  imprimeMatriz(matriz, n, m);
}
