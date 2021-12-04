#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main(){
    Grafo *grafo;
    grafo = criar_grafo(10, 7, 0);

    int inserir1 = insereAresta(grafo, 0, 1, 0 ,0);
    printf("inserir1 : %i\n", inserir1);
    int inserir2 = insereAresta(grafo, 1, 2, 0 ,0);
    printf("inserir2 : %i\n", inserir2);
    int remover1 = removerAresta(grafo, 0, 1, 0);
    printf("remover1 : %i\n", remover1);

    libera_grafo(grafo);    

    return 1;
}
