#include<stdio.h>
#include<stdlib.h>
#include"tp1.h"

//Criar a função para criar a  matriz juntamente com a questão da alocação

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
      printf("%d ", matriz[i][j]);
      j=j+2;
    }
    printf("\n");
  }
  return matriz;
}
