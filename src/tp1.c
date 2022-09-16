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
int encontraDiagonal(int **matriz, int i, int j, int contador, int *cont,int rows, int cols){

  // ENCONTRA DIAGONAL SUPERIOR ESQUERDA
  
  
  if (contador > *cont){
        *cont = contador;
      }
  
  //printf("\n\n ########## ENCONTRA DIAGONAL ############\n\n");
    
  i++ , j--;
  if ( i >= 0 && j >= 0 && i < rows && j < cols){
    if ( matriz [i][j] == 2 ){

      i++, j--;
      if ( i >= 0 && j >= 0 && i < rows && j < cols){
        if ( matriz [i][j] == 0 ){
            contador++;
          
          
          matriz [i][j] = 1;
        
          i--, j++;
          matriz [i][j] = 0;

          i--, j++;
          matriz [i][j] = 0;

          i++, j--;
          i++, j--;

          contador =  encontraDiagonal(matriz ,i , j, contador, cont, rows, cols);
          
          contador--;
          matriz [i][j] = 0;
        }
      }
      i--, j++;
      matriz[i][j] = 2;
    }
  }
  i--, j++;
  matriz[i][j] = 1;
  

  // ENCONTRA DIAGONAL SUPERIOR DIREITA

  i++ , j++;  
  if ( i >= 0 && j >= 0 && i < rows && j < cols){
   if ( matriz [i][j] == 2 ){
      

      i++, j++;

      if ( i >= 0 && j >= 0 && i < rows && j< cols){
        if ( matriz [i][j] == 0 ){

          contador++;
          

          matriz [i][j] = 1;

          i--, j--;
          matriz [i][j] = 0;

          i--, j--;
          matriz [i][j] = 0;

          i++, j++;
          i++, j++;

          contador =  encontraDiagonal(matriz,i,j,contador, cont, rows, cols);
          
          matriz [i][j] = 0;
          contador--;
        }
      }

      
      i--, j--;
      matriz [i][j] = 2;
    }
  }
  i--, j--;
  matriz[i][j] = 1;
    
  // ENCONTRA DIAGONAL INFERIOR ESQUERDA

  i-- , j--;  
  if ( i >= 0 && j >= 0 && i < rows && j < cols){
   if ( matriz [i][j] == 2 ){
     

      i--, j--;

      if ( i >= 0 && j >= 0 && i < rows && j< cols) {
        if ( matriz [i][j] == 0 ){
          
          contador++;

          matriz[i][j] = 1;

          i++, j++;
          matriz[i][j] = 0;

          i++, j++;
          matriz[i][j] = 0;

          i--, j--;
          i--, j--;

          contador =  encontraDiagonal(matriz, i, j, contador, cont, rows, cols);
          
          matriz [i][j] = 0;
          contador--;
        } 
      }

      
      i++, j++;
      matriz [i][j] = 2;  
    }
  }
  i++, j++;
  matriz[i][j] = 1;
  
  // ENCONTRA DIAGONAL INFERIOR DIREITA

  i-- , j++;  
  if ( i >= 0 && j >= 0 && i < rows && j < cols) {
   if ( matriz [i][j] == 2 ){
      

      i--, j++;

      if ( i >= 0 && j >= 0 && i < rows && j< cols){
        if ( matriz [i][j] == 0 ){
          
          contador++;
        
          matriz [i][j] = 1;
          
          i++, j--;
          matriz [i][j] = 0;

          i++, j--;
          matriz [i][j] = 0;

          i--, j++;
          i--, j++;

          contador =  encontraDiagonal(matriz, i, j, contador, cont, rows, cols);
          
          matriz [i][j] = 0;
          contador--;           
        }
      }
      
      i++, j--;
      matriz[i][j] = 2;      
    }
  }
  i++, j--;
  matriz [i][j] = 1; 


   printf("\n\n ENCERROU O ENCONTRA DIAGONAL, retorna CONTADOR: %d \n\n", *cont);
   //imprimeMatriz(matriz,rows,cols);
  
  return contador;
}

