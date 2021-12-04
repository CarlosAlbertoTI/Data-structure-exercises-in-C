#include <stdio.h>
#include <stdlib.h>
#include "./ListDinEncadDesc.h"

struct elemento{
    struct aluno dado;
    struct elemento *prox;
};

typedef struct elemento No;

struct descritor{
    struct elemento *inicio;
    struct elemento *fim;
    int quantidade;
};

Lista* criar_lista(){
    Lista* lista = (Lista*) malloc(sizeof(Lista));
    if(lista != NULL) {
        lista->inicio = NULL;
        lista->fim = NULL;
        lista->quantidade = 0;
    }

    return lista;
}


void libera_lista(Lista *lista){
    if(lista != NULL) {
        No* aux;
        while(lista->inicio != NULL){
            aux = lista->inicio;
            lista->inicio = lista->inicio->prox;
            
            free(aux);
        }
        free(lista);
    }

}

int tamanho_lista(Lista *lista){
    if(lista == NULL) return 0;
    return lista->quantidade;
}

int inserir_lista_inicio(Lista* lista, struct aluno novoAluno){
    if(lista == NULL) return 0;
    
    No *aux = (No*) malloc(sizeof(No));
    if(aux == NULL) return 0;

    aux->dado = novoAluno;
    aux->prox = lista->inicio;
    if(lista->inicio == NULL){
        lista->fim = aux;
    }
    lista->inicio = aux;
    lista->quantidade++;
    return 1;
}

int inserir_lista_fim(Lista* lista,struct aluno novoAluno){
    if(lista == NULL) return 0;
    
    No *aux = (No*) malloc(sizeof(No));
    if(aux == NULL) return 0;

    aux->dado = novoAluno;
    aux->prox = NULL;

    if(lista->inicio == NULL){
        lista->inicio = aux;
    }else{
        lista->fim->prox = aux;
    }

    lista->fim = aux;
    lista->quantidade++;
    return 1;

}

int remover_lista_inicio(Lista* lista){
    if(lista == NULL) return 0;
    if(lista->inicio == NULL) return 0;

    No *aux = lista->inicio;
    lista->inicio = aux->prox;

    free(aux);

    if(lista->inicio == NULL){
        lista->fim = NULL;
    }
    lista->quantidade--;

    return 1;
}

int remover_lista_fim(Lista* lista){
    if(lista == NULL) return 0;
    if(lista->inicio == NULL) return 0;

    No *aux = lista->inicio;
    No *atual = lista->inicio;
    while(aux->prox != NULL){
        atual = aux;
        aux = aux->prox;
    }

    if(aux == lista->inicio){
        lista->inicio = NULL;
        lista->fim = NULL;
    }else{
        atual->prox = aux->prox;
        lista->fim = atual;
    }

    free(aux);
    lista->quantidade--;
    return 1;
}

int imprimir_lista(Lista* lista){
    if(lista == NULL) return 0;
    if(lista->inicio == NULL) return 0;

    printf("IMPRIMINDO LISTA!!!\n\n");

    No *aux = lista->inicio;
    while(aux != NULL){
        printf("Matricula : %d\n",aux->dado.matricula);
        printf("Nome : %s\n",aux->dado.nome);
        printf("Nota1 : %f\n",aux->dado.n1);
        printf("Nota2 : %f\n",aux->dado.n2);
        printf("Nota3 : %f\n",aux->dado.n3);
        aux = aux->prox;
    }
    printf("\n\n");
    return 1;
}