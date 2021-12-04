#include <stdio.h>
#include <stdlib.h>
#include "sort.h" 

int main(){

    criaArquivoTeste("dados.txt");
    mergeSortExterno("dados.txt");

    return 1;
}
