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

void imprime_Grafo(Grafo *grafo){
    if(grafo == NULL)
        return;

    int i, j;
    for(i=0; i < grafo->num_vertices; i++){
        printf("%d: ", i);
        for(j=0; j < grafo->grau[i]; j++){
            if(grafo->eh_ponderado)
                printf("%d(%.2f), ", grafo->arestas[i][j], grafo->pesos[i][j]);
            else
                printf("%d, ", grafo->arestas[i][j]);
        }
        printf("\n");
    }
}

int procuraMenorDistancia(float * distancia, int * visitado, int numVertices){
    int i, menor = -1, primeiro = 1;
    for ( i = 0; i < numVertices; i++){
        if(distancia[i] >= 0 && visitado[i] == 0){
            if(primeiro){
                menor = i;
                primeiro = 0;
            }else{
                if(distancia[i] < distancia[menor]){
                    menor = i;
                }
            }
        }
    }

    return menor;
    
}


void menorCaminho_Grafo(Grafo *grafo, int inicio, int * anterior, float * distancia){
    int i, cont, numVertices, indice,  *visitado, u;
    
    cont = numVertices = grafo->num_vertices;
    visitado = (int*) malloc(numVertices * sizeof(int));

    for(i = 0; i < numVertices; i++){
        anterior[i] = -1;
        distancia[i] = -1;
        visitado[i] = 0;
    }

    distancia[inicio] = 0;
    while(cont > 0){
        
        u = procuraMenorDistancia(distancia, visitado, numVertices);
        if(u == -1) break;

        visitado[u] = 1;
        cont--;

        for(i = 0; i < grafo->grau[u]; i++){
            indice = grafo->arestas[u][i];
            
            if(distancia[indice] < 0){

                distancia[indice] = distancia[u] +1;
                anterior[indice] = u;
            
            }else{

                if(distancia[indice] > distancia[u]){
                    distancia[indice] = distancia[u]+1;
                    anterior[indice] = u;
                }

            }
        }
    }
    free(visitado);
}