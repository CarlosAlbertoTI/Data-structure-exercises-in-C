#include <stdio.h>
#include <stdlib.h>
#include "./StaticQueue.h"

struct fila{
    int inicio, fim , qnt;
    struct aluno dados[MAX];
};

Fila* criar_fila(){
    Fila *fi = (Fila*) malloc(sizeof(struct fila));
    if(fi != NULL){
        fi->inicio = 0;
        fi->fim = 0;
        fi->qnt = 0;
    }
    return fi;
}

void libera_fila(Fila *fila){
    free(fila);
}

int tamanho_fila(Fila *fila){
    if(fila == NULL) return -1;
    return fila->qnt;
}

int fila_cheia(Fila *fila){
    if(fila == NULL) return -1;
    if(fila->qnt == MAX) 
        return 1;
    else
        return 0;
}

int fila_vazia(Fila *fila){
    if(fila == NULL) return -1;
    if(fila->qnt == 0)
        return 1;
    else
        return 0;
}

int insere_fila(Fila *fila, Aluno al){
    if(fila == NULL) return 0;
    if(fila_cheia(fila) == 1) return 0;
    
    fila->dados[fila->fim] = al;
    fila->fim = (fila->fim+1)%MAX;
    fila->qnt++;

    return 1;
}

int remove_fila(Fila *fila){
    if(fila == NULL || fila_vazia(fila) == 1) return 0;
    
    fila->inicio = (fila->inicio+1)%MAX;
    fila->qnt--;
    return 1;
}


int consulta_fila(Fila *fila, Aluno *al){
    if(fila == NULL || fila_vazia(fila) == 1) return 0;

    *al = fila->dados[fila->inicio];
    return 1;
}


int imprime_lista(Fila *fila){
    if(fila == NULL || fila_vazia(fila)) 
        return 0;
    else
        for(int i = fila->inicio; i < fila->fim; i++){
            printf("Matricula: %d\n",fila->dados[i].matricula);
            printf("Nome: %s\n",fila->dados[i].nome);
            printf("N1: %f\n",fila->dados[i].n1);
            printf("N2: %f\n",fila->dados[i].n2);
            printf("N3: %f\n",fila->dados[i].n3);
        }
        return 1;
}