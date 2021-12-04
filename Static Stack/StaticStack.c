#include <stdio.h>
#include <stdlib.h>
#include "./StaticStack.h"

struct pilha {
    int quantidade;
    struct aluno dados[MAX];
};


Pilha* criar_pilha(){
    Pilha* pi;
    pi = (Pilha*) malloc(sizeof(Pilha));
    if(pi != NULL){
        pi->quantidade = 0;
    }
    return pi;
}

void liberar_pilha(Pilha* pi){
    free(pi);
}

int tamanho_pilha(Pilha* pi){
    if(pi == NULL) return -1;
    return pi->quantidade;
}

int pilha_cheia(Pilha* pi){
    if(pi == NULL) return -1;
    return pi->quantidade == MAX;
}

int pilha_vazia(Pilha* pi){
    if(pi == NULL) return -1;
    return pi->quantidade == 0;
}

int inserir_pilha(Pilha* pi, struct aluno al){
    if(pi == NULL) return 0;
    if(pilha_cheia(pi) == 1) return 0;
    pi->dados[pi->quantidade] = al;
    pi->quantidade++;
    return 1;
}

int remove_pilha(Pilha* pi){
    if(pi == NULL) return 0;
    if(pilha_vazia(pi) == 1) return 0;
    pi->quantidade--;
    return 1;
}

int consulta_pilha(Pilha* pi, struct aluno *al){
    if(pi == NULL || pi->quantidade == 0) return 0;
    *al = pi->dados[pi->quantidade-1];
    return 1;

}

int imprime_pilha(Pilha* pi){
    if(pi == NULL || pilha_vazia(pi)) 
        return 0;
    else
        for(int i = 0; i < pi->quantidade; i++){
            printf("Matricula: %d\n",pi->dados[i].matricula);
            printf("Nome: %s\n",pi->dados[i].nome);
            printf("N1: %f\n",pi->dados[i].n1);
            printf("N2: %f\n",pi->dados[i].n2);
            printf("N3: %f\n",pi->dados[i].n3);
        }
        return 1;
}