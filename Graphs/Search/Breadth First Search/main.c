#include <stdio.h>
#include <stdlib.h>
#include "graphs.h"

int main(){
    int eh_digrafo = 1;
    Grafo* grafo = criar_grafo(5, 5, 0);
    
    insereAresta(grafo, 0, 3, eh_digrafo, 0); 
    insereAresta(grafo, 1, 3, eh_digrafo, 0); 
    insereAresta(grafo, 1, 2, eh_digrafo, 0); 
    insereAresta(grafo, 2, 4, eh_digrafo, 0); 
    insereAresta(grafo, 3, 0, eh_digrafo, 0); 
    insereAresta(grafo, 3, 4, eh_digrafo, 0); 
    insereAresta(grafo, 4, 1, eh_digrafo, 0); 

    int visitado[5];

    buscaLargura_grafo(grafo, 0, visitado);

    for (int i = 0; i < 5; i++)
    {
        printf("%i\n", visitado[i]);
    }
    

    libera_grafo(grafo);
    return 1;
}