#ifndef _TP1_H
#define _TP1_H

#include<stdio.h>

FILE *openFile(char *);
void outTable(char *, int *);

int **alocaMatriz(int, int);
void desalocaMatriz(int **, int);
void imprimeMatriz(int **, int, int);

int **montaTabuleiro(FILE *, int **, int, int);
int *quantidade(int **,int, int, int*);

void bruteForce(FILE *);
int encontraDiagonal(int **, int, int, int, int*, int, int);

#endif