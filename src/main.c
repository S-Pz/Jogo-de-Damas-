#include<stdlib.h>
#include"bruteForce.h"

//Para executar o programa tem que usar o ./tp1 -i teste.txt
int main(int argc, char **argv){
    FILE *file;

    file = openFile(argv[2]);

    bruteForce(file);

    //outTable(argv[4], );
    return 0;
}