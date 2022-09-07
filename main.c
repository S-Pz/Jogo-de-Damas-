#include"tp1.h"
#include<stdlib.h>

//Para executar o programa tem que usar o ./tp1 -i teste.txt
int main(int argc, char **argv){

    FILE *file;
    int **matriz,rows,cols,*posi,quant,contador=0,cont=0;

    // for (int i = 0; i < argc; ++i) {
    //     printf("argv[%d]: %s\n", i, argv[i]);
    // }

    file = openFile(argv[2]);
    fscanf(file,"%d %d",&rows,&cols);

    matriz = alocaMatriz(rows, cols);
    matriz = montaTabuleiro(file, matriz, rows, cols);

    //Encontra uns
    printf("Linhas %d Colunas %d", rows, cols);

    posi = quantidade(matriz, rows, cols);
    quant = posi[200];

    int **mirror[quant];

    for(int i=0; i<quant;i++){

        mirror[i] = alocaMatriz(rows, cols);
        mirror[i] = montaTabuleiro(file, mirror[i], rows, cols);
        contador = encontraDiagonal(mirror[i],posi[2*i],posi[(2*i)+1]);
        if (contador > cont){
            cont = contador;
        }    
    }

    imprimeMatriz(matriz,rows,cols);

    for(int i=0; i<quant;i++){

        desalocaMatriz(mirror[i] ,rows);
    }

    desalocaMatriz(matriz,rows);
    free(posi);
    printf("%d",cont);

    fclose(file);
    return 0;
}