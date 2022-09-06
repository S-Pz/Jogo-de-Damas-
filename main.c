#include"tp1.h"
#include<stdlib.h>

//Para executar o programa tem que usar o ./tp1 -i teste.txt
int main(int argc, char **argv){

    FILE *file;
    int **matriz,rows,cols;

    // for (int i = 0; i < argc; ++i) {
    //     printf("argv[%d]: %s\n", i, argv[i]);
    // }

    file = openFile(argv[2]);
    fscanf(file,"%d %d",&rows,&cols);

    printf("Linhas: %d Colunas:%d \n", rows, cols);

    matriz = alocaMatriz(rows, cols);
    matriz = montaTabuleiro(file, matriz, rows, cols);

    // Criar a função para montar o tabuleiro colocando as peças nas casas. Para isso
    // A função terá como parâmetro a matriz e o arquivo.
    // Dentro da função pegar a quantidade de linhas e colunas e realizar o for do arquivo aeds3
    // e desenvolver  a lógica de como será a forma de contagem das jogadas de maneira recursiva ou n;

    desalocaMatriz(matriz,rows);
    fclose(file);

    return 0;
}