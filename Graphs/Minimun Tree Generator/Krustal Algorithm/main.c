#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

int main(){
    int eh_digrafo = 0;
    Grafo* grafo = cria_Grafo(6,6,1);
    insereAresta(grafo,0, 1, eh_digrafo, 6);
    insereAresta(grafo,0, 2, eh_digrafo, 1);
    insereAresta(grafo,0, 3, eh_digrafo, 5);
    insereAresta(grafo,1, 2, eh_digrafo, 2);
    insereAresta(grafo,1, 4, eh_digrafo, 5);
    insereAresta(grafo,2, 3, eh_digrafo, 2);
    insereAresta(grafo,2, 4, eh_digrafo, 6);
    insereAresta(grafo,2, 5, eh_digrafo, 4);
    insereAresta(grafo,3, 5, eh_digrafo, 4);
    insereAresta(grafo,4, 5, eh_digrafo, 3);
    

    int i , pai[6];
    algKruscal_grafo(grafo,0, pai);
    for (int i = 0; i < 6; i++)
    {
        printf("%d: %d\n", pai[i],i);
    }
    libera_Grafo(grafo);
    
    return 0;
}