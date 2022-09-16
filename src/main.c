#include"tp1.h"
#include<stdlib.h>

//Para executar o programa tem que usar o ./tp1 -i teste.txt
int main(int argc, char **argv){

    FILE *file;
    int **matriz, rows = 0 , cols = 0, *posi, quant = 0, contador;

    int *cont = malloc(sizeof(int));
    *cont = 0;

    //Verficar se a entrada(coluna) é par ou impar, para alterar a forma de montar o tabuleiro
    // for (int i = 0; i < argc; ++i) {
    //     printf("argv[%d]: %s\n", i, argv[i]);
    // }
    
    file = openFile(argv[2]);

    fscanf(file,"%d %d", &rows, &cols);

    matriz = alocaMatriz(rows, cols);
    matriz = montaTabuleiro(file, matriz, rows, cols);

    posi = quantidade(matriz, rows, cols);
    quant = posi[200];

    int **mirror;
    contador = 0;
    
    for(int i=0; i<quant;++i){

        // mirror = alocaMatriz(rows, cols);
        // //imprimeMatriz(mirror, rows, cols);
        // mirror = montaTabuleiro(file, mirror, rows, cols);
        // contador = 0;
        // contador = encontraDiagonal(mirror, posi[2*i], posi[(2*i)+1],contador,cont,rows,cols);
        
        // desalocaMatriz(mirror, rows);
        
        contador = encontraDiagonal(matriz, posi[2*i], posi[(2*i)+1],contador,cont,rows,cols);   

        //if (contador > cont){
        //    cont = contador;
        //} 
        
    }
    
    //imprimeMatriz(matriz, rows, cols);

    desalocaMatriz(matriz, rows);
    free(posi);
    printf("RESULTADO FINAL: %d", *cont);

    fclose(file);
    return 0;
}