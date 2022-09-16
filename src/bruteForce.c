#include<stdio.h>
#include<stdlib.h>
#include"bruteForce.h"

void bruteForce(FILE *file){

  int **matriz, rows, cols , contador;
  
  // cria uma matriz, rows e cols para armazenar a quantidade de linhas e colunas
  // quant irá armazenar a quantidade de peças suas no tabuleiro
  // contador irá contar as jogadas
  
  while(1){

    fscanf(file,"%d %d", &rows, &cols); // lê a quantidade de linhas e colunas no arquivo

    if(rows ==0 && cols==0){
      break;
      
    }else if((rows >= 3 && rows <=20 && cols >= 3 && cols <=20) && ((rows * cols) <= 200)){ // verifica se a entrada é valida

      int *cont = malloc(sizeof(int));  // cont irá armazenar sempre o MAX, referente as suas jogadas.
      int *posi = malloc(201 * sizeof(int)); // posi irá armazenar as posições das suas peças, além de quantas são

      matriz = alocaMatriz(rows, cols); // cria a matriz com seu respectivo tamanho
      matriz = montaTabuleiro(file, matriz, rows, cols); // monta o tabuleiro de acordo com as entradas

      // printf("\nmatriz de entrada:\n\n "); 
      //imprimeMatriz(matriz, rows, cols); // printa o tabuleiro pronto

      posi = quantidade(matriz, rows, cols, posi); // posi recebe a quantidade de peças suas no tabuleiro e suas coordenadas

      *cont = 0; // inicia a contagem MAX

      for(int i=0; i<posi[200];++i){ // faz um laço para percorrer cada peça sua
        contador = 0; // inicia a contagem desta peça
        encontraDiagonal(matriz, posi[2*i], posi[(2*i)+1],contador, cont,rows,cols); // encontra a melhor jogada para esta peça
      }

      //printf("\nRESULTADO FINAL: %d", *cont); // retorna a contagem MAX.
      outTable(argv[4], cont);
      
      desalocaMatriz(matriz, rows);
      free(posi);
      free(cont);
      
    }else{ // caso a entrada seja invalida retorna a mensagem
      printf ("ENTRADA INVALIDA: LINHAS E COLUNAS DEVEM SER MAIOR QUE 1");
    }
  }
  fclose(file);
}

FILE *openFile(char *file){
  
  FILE *arq;
  arq = fopen(file,"r");
  
  return arq;
}

void outTable(char *file, int *cont){

  FILE *saved;
  saved = fopen(file,"a+");

  fprintf(saved,"%d\n", *cont);

  fclose(saved);
}

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
  
  //a função montaTabuleiro lê o arquivo de entrada, verifica se as entradas são validas
  //e caso seja válido, aloca as peças em suas posições sequencialmente
  //montaTabuleiro recebe o arquivo, a matriz que será utilizada com a quantidade de linhas e colunas.
  
  int j,a; 
  //j será usado no for,porém o seu valor precisa ser atualizado antes dependendo se estamos em uma linha par ou impar.
  // "a" receberá os valores da entrada.
  
  for(int i = 0; i<rows; i++){  // laço que percorre todas as linhas
    if((i%2) == 0){ // verifica se a linha é par ou impar
      j=0;  // caso seja par, j inicial é 0   

    }else{      
      j=1; // caso seja impar, j inicial é 1

    }

    while(j<cols){ // laço que percorre todas as colunas
      fscanf(arq, "%d", &a); // lê o arquivo e armazena o valor em "a" 
      if(a == 0 || a == 1 || a == 2){ // verifica se a entrada é valida (vazio, peça sua, peça inimga)
        matriz[i][j]= a; // se válido, a posição [i][j] da matriz recebe o valor de "a"    

      }else{
        printf("\n ENTRADA INVALIDA: As opções de entrada são 0 ,1 e 2 \n\n");
        // caso seja invalido, retorna mensagem.
        return 0; // sai da função

      }
      j=j+2; //vai para a coluna seguinte

    }
  }
  return matriz; // retorna a matriz montada
}

void imprimeMatriz(int **matriz, int rows, int cols){
  
  // função imprimeMatriz serve para demonstrar analogamente o tabuleiro de damas com seu tamanho e peças.
  // recebe a matriz, quantidade de linhas e colunas.

  int j; //j será usado no for,porém o seu valor precisa ser atualizado antes dependendo se estamos em uma linha par ou impar.
  for(int i = 0; i<rows; i++){ // laço que percorre todas as linhas

    if((i%2)==0){ // verifica se a linha é par ou impar
      j=0; // caso seja par, j inicial é 0

    }else{
      j= 1; // caso seja impar, j inicial é 1
      printf(" "); // caso seja impar, desloca um espaço na matriz

    }
    while(j<cols){ // laço que percorre todas as colunas
      printf(" %d ",matriz[i][j]); // printa a peça daquela coordenada [i],[j] no tabuleiro
      j = j+2; // vai para a coluna seguinte

    }
    printf("\n"); //pula para a linha seguinte

  }
}

int *quantidade(int **matriz,int rows, int cols, int *posi){
  
  // A função quantidade serve para encontrar a quantidade de peças suas no tabuleiro
  // com esta informação vou chamar a função encontraDiagonal para cada peça sua.
  // função quantidade recebe uma matriz, quantidade de linhas e colunas
  
  int j=0, a=0, b=0; 
 
  // j será usado no for,porém o seu valor precisa ser atualizado antes dependendo se estamos em uma linha par ou impar.
  // a e b serão usados para guardar informaçções e *posi, ex: posi[0] e posi[1] serão coordenadas da sua primeira peça.
  // *posi será o retorno da função, armazenando as coordenadas e também a quantidade.
  
  //posi = malloc( sizeof(int) * 201); // aloca 201 posições em posi.

  for(int i=0; i<rows; i++){ // laço que percorre todas as linhas
    if(i%2 == 0){ // verifica se a linha é par ou impar
      j=0; // caso seja par, j inicial é 0

    }else{
      j=1; // caso seja impar, j inicial é 1

    }
    for(; j<cols; j=j+2){ // laço que percorre todas as colunas

      if(matriz[i][j] == 1){ // encontra uma peça sua
        b= 2*a; // atualiza em qual espaço dentro do vetor posi deverá ser guardada a posição desta peça
        posi[b] = i; // armazena a linha

        b++; //deloca para a posição seguinte do vetor posi
        posi[b] = j; // armazena a coluna

        a++; // atualiza a quantidade de peças suas encontradas.
        posi[200] = a; // armazena a quantidade na ultima casa do vetor posi.

      }
    }
  }
  return posi; // retorna o vetor posi com as coordenas e também a quantidade de peças suas encontradas
}

int encontraDiagonal(int **matriz, int i, int j, int contador, int *cont,int rows, int cols){
  
  // A função encontraDiagonal verifica as possibilidades de uma peça sua comer uma peça inimiga e conta a maior possibilidade.
  // função encontraDiagonal, recebe uma matriz, i e j são as posições da matriz em que estamos trabalhando
  // cont é um inteiro que armazena a jogada Maxima , rows e cols é a quantidade de linhas e colunas.
  
  if (contador > *cont){// verifica se a jogada que está ocorrendo é maior que a MAX já registrada.
    *cont = contador; // Atualiza o valor MAX.
  }
            
  // ENCONTRA DIAGONAL SUPERIOR ESQUERDA
    
  i++ , j--;  // desloca para a diagonal                                     
  if ( i >= 0 && j >= 0 && i < rows && j < cols){  // confere se não saiu do tabuleiro 
    if ( matriz [i][j] == 2 ){ //verifica se é uma peça inimiga
      i++, j--; // desloca para a mesma diagonal
      if ( i >= 0 && j >= 0 && i < rows && j < cols){ // confere se não saiu do tabuleiro 
        if ( matriz [i][j] == 0 ){ // verifica se é um espaço vazio
          contador++;  // Efetua a Comida
              
          // Atualiza as peças e espaços no tabileiro:
          matriz [i][j] = 1; // a sua peça passa a ocupar o espaço que antes era vazio
          i--, j++; // retorna uma diagonal

          matriz [i][j] = 0; // a peça inimiga sai do tabuleiro deixando o espaço vazio
          i--, j++; // retorna a posição original
          
          matriz [i][j] = 0; // o espaço em que estava a sua peça fica vazio
          
          i++, j--; // avança novamente uma diagonal
          i++, j--; // avança novamente uma diagonal para continuar de onde paramos
          
          contador =  encontraDiagonal(matriz ,i , j, contador, cont, rows, cols); // verifica se há como continuar comendo
          contador--; // desfaz a jogada para tentarmos outro caminho
          
          //volta as peças ao lugar original:
          matriz [i][j] = 0; // recoloca o espaço vazio
        }
      }
      i--, j++; // retorna uma diagonal
      matriz [i][j] = 2; //volta a peça inimiga
    }
  }

  i--, j++; // retorna a posição original
  matriz [i][j] = 1; //volta a sua peça

  // ENCONTRA DIAGONAL SUPERIOR DIREITA
  
  i++ , j++;   // desloca para a diagonal 
  if ( i >= 0 && j >= 0 && i < rows && j < cols){ // confere se não saiu do tabuleiro 
    if ( matriz [i][j] == 2 ){ //verifica se é uma peça inimiga
      i++, j++; // desloca para a mesma diagonal

      if ( i >= 0 && j >= 0 && i < rows && j< cols){ // confere se não saiu do tabuleiro 
        if ( matriz [i][j] == 0 ){ // verifica se é um espaço vazio
          contador++; // Efetua a Comida
          // Atualiza as peças e espaços no tabileiro
          
          matriz [i][j] = 1; // a sua peça passa a ocupar o espaço que antes era vazio
          i--, j--; // retorna uma diagonal

          matriz [i][j] = 0; // a peça inimiga sai do tabuleiro deixando o espaço vazio
          i--, j--; // retorna a posição original

          matriz [i][j] = 0; // o espaço em que estava a sua peça fica vazio
          
          i++, j++; // avança novamente uma diagonal
          i++, j++; // avança novamente uma diagonal para continuar de onde paramos

          contador =  encontraDiagonal(matriz,i,j,contador, cont, rows, cols); // verifica se há como continuar comendo
          contador--; // desfaz a jogada para tentarmos outro caminho

          matriz [i][j] = 0; // recoloca o espaço vazio
        }
      }
      i--, j--; // retorna uma diagonal
      matriz [i][j] = 2; //volta a peça inimiga

    }
  }

  i--, j--; // retorna a posição original
  matriz [i][j] = 1; //volta a sua peça
   
  // ENCONTRA DIAGONAL INFERIOR ESQUERDA

  i-- , j--;  // desloca para a diagonal
  if ( i >= 0 && j >= 0 && i < rows && j < cols){ // confere se não saiu do tabuleiro 
    if ( matriz [i][j] == 2 ){ //verifica se é uma peça inimiga
      i--, j--; // desloca para a mesma diagonal

      if ( i >= 0 && j >= 0 && i < rows && j< cols) { // confere se não saiu do tabuleiro 
        if ( matriz [i][j] == 0 ){ // verifica se é um espaço vazio
          contador++; // Efetua a Comida
          
          // Atualiza as peças e espaços no tabileiro
          matriz [i][j] = 1; // a sua peça passa a ocupar o espaço que antes era vazio
          i++, j++; // retorna uma diagonal

          matriz [i][j] = 0; // a peça inimiga sai do tabuleiro deixando o espaço vazio
          i++, j++; // retorna a posição original

          matriz [i][j] = 0; // o espaço em que estava a sua peça fica vazio

          i--, j--; // avança novamente uma diagonal
          i--, j--; // avança novamente uma diagonal para continuar de onde paramos
          
          contador =  encontraDiagonal(matriz, i, j, contador, cont, rows, cols); // verifica se há como continuar comendo
          contador--; // desfaz a jogada para tentarmos outro caminho

          //volta as peças ao lugar original:
          matriz [i][j] = 0; // recoloca o espaço vazio
        } 
      }

      i++, j++; // retorna uma diagonal
      matriz [i][j] = 2; //volta a peça inimiga

    }
  }

  i++, j++; // retorna a posição original
  matriz [i][j] = 1; //volta a sua peça
  
  // ENCONTRA DIAGONAL INFERIOR DIREITA

  i-- , j++;  // desloca para a diagonal 
  if ( i >= 0 && j >= 0 && i < rows && j < cols) { // confere se não saiu do tabuleiro 
    if ( matriz [i][j] == 2 ){ //verifica se é uma peça inimiga
      i--, j++; // desloca para a mesma diagonal

      if ( i >= 0 && j >= 0 && i < rows && j< cols){ // confere se não saiu do tabuleiro 
        if ( matriz [i][j] == 0 ){ // verifica se é um espaço vazio
          contador++; // Efetua a Comida
          
          // Atualiza as peças e espaços no tabileiro 
          matriz [i][j] = 1; // a sua peça passa a ocupar o espaço que antes era vazio 
          i++, j--; // retorna uma diagonal

          matriz [i][j] = 0; // a peça inimiga sai do tabuleiro deixando o espaço vazio

          i++, j--; // retorna a posição original
          matriz [i][j] = 0; // o espaço em que estava a sua peça fica vazio

          i--, j++; // avança novamente uma diagonal
          i--, j++; // avança novamente uma diagonal para continuar de onde paramos
          
          contador =  encontraDiagonal(matriz, i, j, contador, cont, rows, cols); // verifica se há como continuar comendo
          contador--; // desfaz a jogada para tentarmos outro caminho

          //volta as peças ao lugar original:
          matriz [i][j] = 0;  // recoloca o espaço vazio
        }
      }

      i++, j--;  // retorna uma diagonal
      matriz [i][j] = 2; //volta a peça inimiga

    }
  }
  
  i++, j--; // retorna a posição original
  matriz [i][j] = 1; //volta a sua peça

  //printf("\n ENCERROU O ENCONTRA DIAGONAL, CONTADOR: %d \n", contador);
  //printf(" ENCERROU O ENCONTRA DIAGONAL, CONT MAX: %d \n\n", *cont);
  //imprimeMatriz(matriz,rows,cols);
  
  return contador; // retorna se comeu ou não uma peça
}