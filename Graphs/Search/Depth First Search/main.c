#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main(){
    Grafo *grafo;
    grafo = criar_grafo(10, 7, 0);

    int eh_digrafo = 1;

    insereAresta(grafo, 0, 1, eh_digrafo ,0);
    insereAresta(grafo, 1, 3, eh_digrafo ,0);
    insereAresta(grafo, 1, 2, eh_digrafo ,0);
    insereAresta(grafo, 2, 4, eh_digrafo ,0);
    insereAresta(grafo, 3, 0, eh_digrafo ,0);
    insereAresta(grafo, 3, 4, eh_digrafo ,0);
    insereAresta(grafo, 4, 1, eh_digrafo ,0);
    
    int visitado[5];

    buscaProfundidade_Grafo(grafo, 0, visitado);
   
    

    libera_grafo(grafo);    

    return 1;
}
