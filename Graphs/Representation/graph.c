#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

struct grafo {
    int eh_ponderado;
    int num_vertices;
    int grau_max;
    int** arestas;
    float** pesos;
    int* grau;
};

Grafo *criar_grafo(int num_vertices, int grau_max, int eh_ponderado){
    Grafo *grafo;
    grafo = (Grafo*) malloc(sizeof(struct grafo));
    if(grafo != NULL){
        int i;
        grafo->num_vertices = num_vertices;
        grafo->grau_max = grau_max;
        grafo->eh_ponderado = (eh_ponderado != 0)?1:0;
        grafo->grau = (int*) calloc(num_vertices,sizeof(int));

        grafo->arestas = (int**) malloc(num_vertices * sizeof(int*));
        for(i=0; i<num_vertices; i++)
            grafo->arestas[i] = (int*) malloc(grau_max * sizeof(int));

        if(grafo->eh_ponderado){
            grafo->pesos = (float**) malloc(num_vertices * sizeof(float*));
            for(i=0; i<num_vertices; i++)
                grafo->pesos[i] = (float*) malloc(grau_max * sizeof(float));
        }

    }
    return grafo;
}

void libera_grafo(Grafo* grafo){
    if(grafo != NULL){
        int i;
        for(i=0; i<grafo->num_vertices; i++)
            free(grafo->arestas[i]);
        free(grafo->arestas);

        if(grafo->eh_ponderado){
            for(i=0; i<grafo->num_vertices; i++)
                free(grafo->pesos[i]);
            free(grafo->pesos);
        }
        free(grafo->grau);
        free(grafo);
    }
}

int insereAresta(Grafo* grafo, int orig, int dest, int eh_digrafo, float peso){
    if(grafo == NULL)
        return 0;
    if(orig < 0 || orig >= grafo->num_vertices)
        return 0;
    if(dest < 0 || dest >= grafo->num_vertices)
        return 0;

    grafo->arestas[orig][grafo->grau[orig]] = dest;
    if(grafo->eh_ponderado)
        grafo->pesos[orig][grafo->grau[orig]] = peso;
    grafo->grau[orig]++;

    if(eh_digrafo == 0)
        insereAresta(grafo,dest,orig,1,peso);
    return 1;
}

int removerAresta(Grafo* grafo, int origem, int destino, int eh_digrafo){
    if(grafo == NULL)
        return 0;
    if(origem < 0 || origem >= grafo->num_vertices)
        return 0;
    if(destino < 0 || destino >= grafo->num_vertices)
        return 0;
    
    int i;
    while(i < grafo->grau[origem] && grafo->arestas[origem][i] != destino){
        i++;
    }

    if(i == grafo->grau[origem])
        return 0;

    grafo->grau[origem]--;
    grafo->arestas[origem][i] =  grafo->arestas[origem][grafo->grau[origem]];
    if(grafo->eh_ponderado){
        grafo->pesos[origem][i] =  grafo->pesos[origem][grafo->grau[origem]];
    }

    if(eh_digrafo == 0){
        removerAresta(grafo, destino, origem, 1);
    }
    return 1;
}