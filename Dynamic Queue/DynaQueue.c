#include <stdio.h>
#include <stdlib.h>
#include "./DynaQueue.h"

struct elemento{
    struct aluno dado;
    struct elemento *proximo;
};

struct fila{
    struct elemento *inicial;
    struct elemento *final;
};

typedef struct elemento No;


Fila* criar_fila(){
    Fila *fi = (Fila*) malloc(sizeof(Fila));
    if(fi != NULL){
        fi->inicial = NULL;
        fi->final = NULL;
    }
    return fi;
}

void liberar_fila(Fila *fila){
    if(fila != NULL){
        No* aux;
        while(fila->inicial != NULL){
            aux = fila->inicial;
            fila->inicial = fila->inicial->proximo;
            free(aux);
        }
        free(fila);
    }
}

int tamanho_fila(Fila *fila){
    if(fila == NULL) return 0;
    int count = 0;
    No* aux = fila->inicial;
    while(aux != NULL){
        count++;
        aux = aux->proximo;
    }
    return count;
}

int fila_cheia(Fila *fila){
    return 0;
}

int fila_vazia(Fila *fila){
    if(fila == NULL) return -1;
    if(fila->inicial == NULL){
        return 1;
    }
    return 0;
}

int insere_fila(Fila *fila,Aluno al){
    if(fila == NULL) return 0;
    No *aux = (No*) malloc(sizeof(No));
    if(aux == NULL) return 0;

    aux->dado = al;
    aux->proximo = NULL;

    if(fila->final == NULL){
        fila->inicial = aux;
    }else{
        fila->final->proximo = aux;
    } 
    fila->final = aux;
    return 1;
}

int remove_fila(Fila *fila){
    if(fila == NULL) return 0;
    if(fila->inicial == NULL) return 0;
    
    No *aux = fila->inicial;
    fila->inicial = fila->inicial->proximo;

    if(fila->inicial == NULL){
        fila->final = NULL;
    }
    free(aux);
    return 1;
}

int consulta_fila(Fila *fila, Aluno *al){
    if(fila == NULL) return 0;
    if(fila_vazia(fila) == 1) return 0;

    *al = fila->inicial->dado;
    return 1;
}

int imprime_lista(Fila *fila){
    if(fila == NULL) return 0;
    if(fila_vazia(fila) == 1) return 0;

    No *aux = fila->inicial;
    while(aux != NULL){
        printf("Matricula: %d\n",aux->dado.matricula);
        printf("Nome: %s\n",aux->dado.nome);
        printf("N1: %f\n",aux->dado.n1);
        printf("N2: %f\n",aux->dado.n2);
        printf("N3: %f\n",aux->dado.n3);
        aux = aux->proximo;
    }
    return 1;
}