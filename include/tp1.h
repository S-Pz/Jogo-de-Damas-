#ifndef _TP1_H
#define _TP1_H

#include<stdio.h>

//Função para retornar o arquivo, um ponteiro para o ínicio do arquivo
//Função para a montagem do tabuleiro, terá como parâmtro o ponteiro para o arquivo aberto.

// Criar uma função aloca matriz
// Dentro da função aloca matriz, chamar a função monta tabuleiro

//Montar o tabuleiro, preciso do arquivo, fazer um for para ler a quantidade de linhas e colunas
//fazer outro laço para pegar a casa das peça e realizar a distribuição pelo tabuleiro


FILE *openFile(char *);
int **alocaMatriz(int, int);
void desalocaMatriz(int **, int);
int **montaTabuleiro(FILE *, int **, int, int);
void imprimeMatriz(int **, int, int);

int *quantidade(int **,int, int);
int encontraDiagonal(int **, int, int, int, int*, int, int);
void jogadas(int **, int , int ,int, int);

#endif