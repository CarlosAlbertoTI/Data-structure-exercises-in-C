#include <stdio.h>
#include <stdlib.h>
#include "./DynamicStack.h"


struct elemento{
    struct aluno dados;
    struct elemento* proximo;
};

typedef struct elemento No;

Pilha* criar_pilha(){
    Pilha* pi = (Pilha*) malloc(sizeof(Pilha));
    if(pi != NULL){
        *pi = NULL;
    }
    return pi;
}

void liberar_pilha(Pilha* pi){
    if(pi != NULL){
        No* no;
        while((*pi) != NULL){
            no = (*pi);
            (*pi) = (*pi)->proximo;
            free(no);
        }
        free(pi);
    }
}

int tamanho_pilha(Pilha* pi){
    if(pi == NULL) return 0;
    int count = 0;
    No* no = (*pi);
    while(no != NULL){
        count++;
        no = no->proximo;
    }
    return count;
}

int pilha_cheia(Pilha* pi){
    return 0;
}

int pilha_vazia(Pilha* pi){
    if(pi == NULL || (*pi) == NULL) return 1;
    return 0;
}

int inserir_pilha(Pilha* pi, struct aluno al){
    if(pi == NULL) return 0;

    No* no = (No*) malloc(sizeof(No));
    if(no == NULL) return 0;

    no->dados = al;
    no->proximo = (*pi);
    (*pi) = no;
    return 1;
}

int remove_pilha(Pilha* pi){
    if(pi == NULL || (*pi) == NULL) return 0;
    No* no = (*pi);
    (*pi) = no->proximo;
    free(no);
    return 1;
}

int consulta_pilha(Pilha* pi, struct aluno *al){
    if(pi == NULL || (*pi) == NULL) return 0;
    *al = (*pi)->dados;
    return 1;
}

int imprime_pilha(Pilha *pi){
    if(pi == NULL) return 0;
    if(pilha_vazia(pi) == 1) return 0;

    No* aux = (*pi);
    while(aux != NULL){
        printf("Matricula: %d\n",aux->dados.matricula);
        printf("Nome: %s\n",aux->dados.nome);
        printf("N1: %f\n",aux->dados.n1);
        printf("N2: %f\n",aux->dados.n2);
        printf("N3: %f\n",aux->dados.n3);
        aux = aux->proximo;
    }
    return 1;
}