#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

int main(){
    ArvBinaria* raiz = cria_arvoreB();

    int estaV = estaVazia_ArvoreB(raiz);
    if(estaV == 1){
        printf("AVB esta vazia\n");
    }

    int inserir1 = inserir_ArvoreB(raiz, 10);
    printf("inserir1: %i\n", inserir1);

    int inserir2 = inserir_ArvoreB(raiz, 5);
    printf("inserir2: %i\n", inserir2);
    
    int inserir3 = inserir_ArvoreB(raiz, 15);
    printf("inserir3: %i\n", inserir3);
    
    int inserir4 = inserir_ArvoreB(raiz, 12);
    printf("inserir4: %i\n", inserir4);
    
    int inserir5 = inserir_ArvoreB(raiz, 19);
    printf("inserir5: %i\n", inserir5);
    
    int altura1 = altura_arvoreB(raiz);
    printf("altura AVB: %d\n", altura1);

    int tNos = total_NO_arvoreB(raiz);
    printf("Total de NOS: %d\n", tNos);

    int remove1 = remove_ArvoreB(raiz, 10);

    preOrdem_ArvoreB(raiz);
    printf("------\n");
    emOrdem_ArvoreB(raiz);
    printf("------\n");
    posOrdem_ArvoreB(raiz);
    
    libera_ArvBin(raiz);

    return 1;
}

