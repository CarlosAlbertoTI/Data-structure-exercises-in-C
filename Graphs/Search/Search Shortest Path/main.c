#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main(){

    Grafo *grafo;
    grafo = criar_grafo(5, 5, 0);

    int eh_digrafo = 1;

    insereAresta(grafo, 0, 1, eh_digrafo ,0);
    insereAresta(grafo, 1, 3, eh_digrafo ,0);
    insereAresta(grafo, 1, 2, eh_digrafo ,0);
    insereAresta(grafo, 2, 4, eh_digrafo ,0);
    insereAresta(grafo, 3, 0, eh_digrafo ,0);
    insereAresta(grafo, 3, 4, eh_digrafo ,0);
    insereAresta(grafo, 4, 1, eh_digrafo ,0);
    
    int anterior[5];
    float distancia[5];

    menorCaminho_Grafo(grafo, 0, anterior, distancia);

    for(int i = 0; i < 5; i++){
        printf("%.0f\n", distancia[i]);
    }

    imprime_Grafo(grafo);

    libera_grafo(grafo);

    return 1;
}