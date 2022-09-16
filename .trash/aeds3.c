#include<stdio.h>
#include<math.h>

int main(){
    
    FILE *arq;
    
    int j, a, n, m, contador, cont;

    arq = fopen("entrada.txt","r");
    fscanf(arq, "%d %d", &n,&m);
    //fscanf(arq, "\n");

    int matriz[n][m];

    for(int i=0; i<n; i++){

            // 0%2 = 0
            // 1%2 = 1
            // 2%2 = 0
                              
        if((i%2) == 0){
            j=0;
            //printf("IF\n");
        }else{
            //printf("ELSE\n");
            j=1;
        }
        while(j<m){
            
            fscanf(arq, "%d", &a);

            matriz[i][j]= a;
            printf("%d ", matriz[i][j]);
            j = j+2;    
        }
        printf("\n");
    }  
    
    // for(int i=0; i<n; i++){

    //     if((i%2) == 0){
    //         j=0;
    //     }else{
    //         j=1;
    //     }
    //     for(; j<3; j++){
    //         printf("%d ", matriz[i][j]);
    //     }
    //    printf("\n");   
    // }

    //Parte teste para pegar o valor 1
    /*for(int i=0; i<3; i++){

        if(i%2 == 0){
            j=0;
        }else{
            j=1;
        }

        for(; j<3; j=j+2){

            if(matriz[i][j] == 1){
                20 somar um no i, somar 1 no j;
                22     ||       ,subtrair 2 no j;
                00 subtrair 2 no i, ||          ;
                02 somar 2 no j                 ;
            }
            
            i++ , j ++;
            if ( i > 0 && j > 0 && i < n && j< m) {
                if ( matriz [i][j] == 2 ){
                    i++, j++;
                    if ( i > 0 && j > 0 && i < n && j< m) {
                        if ( matriz [i][j] == 0 ){ 
                            contador++;
                        }
                    }
                }
            }
        }
        
       printf("\n");   
    }*/
    /*
    for(int i=0; i<n; i++){
        
        if(i%2 == 0){
            j=0;
        }else{
            j=1;
        }

        for(; j<m; j=j+2){

            if(matriz[i][j] == 1){
                printf("encontrou o 1 \n");

                i++ , j++;
                if ( i >= 0 && j >= 0 && i < n && j < m) {
                    if (matriz[i][j] == 2){

                        printf("encontrou o 2 \n");

                        i++, j++;
                        if ( i >= 0 && j >= 0 && i < n && j < m) {
                            if (matriz [i][j] == 0 ){
                                printf("encontrou o 0\n");
                                contador++;
                            }
                        }
                        i--, j--;
                    }
                }
                i--, j--;
                
                i++ , j--;  
                if ( i >= 0 && j >= 0 && i < n && j < m) {
                    if (matriz[i][j] == 2){
                        printf("encontrou o 2\n");
                        i++, j--;
                        if ( i >= 0 && j >= 0 && i < n && j< m) {
                            if( matriz[i][j] == 0 ){
                                printf("encontrou o 0 \n");
                                contador++;
                            }
                        }
                        i--, j++;
                    }
                }
                i--, j++;
                
                i-- , j++;  
                if ( i >= 0 && j >= 0 && i < n && j < m) {
                    if (matriz[i][j] == 2 ){
                        printf("encontrou o 2 \n");
                        i--, j++;
                        if ( i >= 0 && j >= 0 && i < n && j< m) {
                            if (matriz [i][j] == 0){
                                printf("encontrou o 0 \n");
                                contador++;
                            }
                        }
                        i++, j--;
                    }
                }
                i++, j--;
                
                i-- , j--;  
                if ( i >= 0 && j >= 0 && i < n && j < m){
                    if ( matriz[i][j] == 2 ){
                        printf("encontrou o 2 \n");
                        i--, j--;
                        if ( i >= 0 && j >= 0 && i < n && j< m) {
                            if ( matriz [i][j] == 0 ){
                                printf("encontrou o 0 \n");
                                contador++;
                            }
                        }
                        i++, j++;
                    }
                }
                i++, j++;
            }
            contador = 0;
        }
    }
    printf(" o numero de jogadas foi: %d \n" , contador);*/

     for(int i=0; i<n; i++){
        if(i%2 == 0){
            j=0;
        }else{
            j=1;
        }

        for(; j<m; j=j+2){
    contador = 0;
AQUI:       
            if(matriz[i][j] == 1){
            printf("encontrou o 1 \n");
                i++ , j++;
                if ( i >= 0 && j >= 0 && i < n && j < m) {
                    if ( matriz [i][j] == 2 ){
                        
                        printf("encontrou o 2 \n");

                        i++, j++;
                        if ( i >= 0 && j >= 0 && i < n && j < m) {
                            if ( matriz [i][j] == 0 ){
                                printf("encontrou o 0 \n");
                                contador++;
                                matriz [i][j] = 1;
                                if(contador>cont){
                                    cont = contador;
                                }
                                i--, j--;
                                matriz [i][j] = 0;
                                i--, j--;
                                matriz [i][j] = 0;
                                i++, j++;
                                i++, j++;
                                goto AQUI;
                            }
                        }
                        i--, j--;
                    }
                }
                i--, j--;

                
                i++ , j--;  
                if ( i >= 0 && j >= 0 && i < n && j < m) {
                    if ( matriz [i][j] == 2 ){
                        printf("encontrou o 2 \n");
                        i++, j--;
                        if ( i >= 0 && j >= 0 && i < n && j< m) {
                            if ( matriz [i][j] == 0 ){
                                printf("encontrou o 0 \n");
                                contador++;
                                matriz [i][j] = 1;
                                if(contador>cont){
                                    cont = contador;
                                }
                                i--, j++;
                                matriz [i][j] = 0;
                                i--, j++;
                                matriz [i][j] = 0;
                                i++, j--;
                                i++, j--;
                                goto AQUI;
                            }
                        }
                        i--, j++;
                    }
                }
                i--, j++;

                
                i-- , j++;  
                if ( i >= 0 && j >= 0 && i < n && j < m) {
                    if ( matriz [i][j] == 2 ){
                        printf("encontrou o 2 \n");
                        i--, j++;
                        if ( i >= 0 && j >= 0 && i < n && j< m) {
                            if ( matriz [i][j] == 0 ){
                                printf("encontrou o 0 \n");
                                contador++;
                                matriz [i][j] = 1;
                                if(contador>cont){
                                    cont = contador;
                                }
                                i++, j--;
                                matriz [i][j] = 0;
                                i++, j--;
                                matriz [i][j] = 0;
                                i--, j++;
                                i--, j++;
                                goto AQUI;
                            }
                        }
                        i++, j--;
                    }
                }
                i++, j--;

                
                i-- , j--;  
                if ( i >= 0 && j >= 0 && i < n && j < m) {
                    if ( matriz [i][j] == 2 ){
                        printf("encontrou o 2 \n");
                        i--, j--;
                        if ( i >= 0 && j >= 0 && i < n && j< m) {
                            if ( matriz [i][j] == 0 ){
                                printf("encontrou o 0 \n");
                                contador++;
                                matriz [i][j] = 1;
                                if(contador>cont){
                                    cont = contador;
                                }
                                i++, j++;
                                matriz [i][j] = 0;
                                i++, j++;
                                matriz [i][j] = 0;
                                i--, j--;
                                i--, j--;
                                goto AQUI;
                            }
                        }
                        i++, j++;
                    }
                }
                i++, j++;
            }
            
        }
        
    }
    
    printf(" o numero de jogadas foi: %d \n" , cont);

    for(int i=0; i<n; i++){

        if((i%2) == 0){
            j=0;
        }else{
            j=1;
        }
        while(j<m){

            printf("%d ", matriz[i][j]);
            j = j+2;    
        }
        printf("\n");   
    }
    fclose(arq);
    return 0;
}