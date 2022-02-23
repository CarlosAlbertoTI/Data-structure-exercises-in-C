#include <stdio.h>
#include <stdlib.h>
#include "SkipList.h"


int main(){

    SkipList* sk = criar_skipList(3, 0.5);

    int teste1 = inserir_skipList(sk, 5);
    int teste2 = inserir_skipList(sk, 10);
    int teste3 = inserir_skipList(sk, 20);

    printf("%i - %i - %i \n", teste1, teste2, teste3);
    int teste4 = buscar_skipList(sk, 10);
    int teste5 = buscar_skipList(sk, 20);

    printf("%i - %i \n", teste4, teste5);
    
    int teste6 = remove_skipList(sk, 10);

    printf("%i ", teste6);
    // printf("%i - %i - %i", teste1, teste2, teste3);

    liberarSkipList(sk);
    return 0;
}