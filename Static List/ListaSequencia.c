#include <stdlib.h>
#include <stdio.h>
#include "ListaSequencia.h"

struct lista {
    int qtd;
    struct aluno dados[MAX];
};

Lista* criarLista(){
    Lista* li;
    li = (Lista*) malloc(sizeof(struct lista));
    if(li != NULL){
        li -> qtd = 0;
    }
    return li;
}

void liberaLista(Lista* li){
    free(li);
}

int tamanhoLista(Lista* li){
    if(li == NULL){
        return -1;
    }else{
        return li->qtd;
    }
}

int listaCheia(Lista* li){
    if(li == NULL){
        return -1;
    }else{
        return li->qtd == MAX;
    }
}

int insereListaFinal(Lista* li, struct aluno al){
    if(li == NULL){
        return 0;
    }
    if(listaCheia(li)){
        return 0;
    }
    li->dados[li->qtd] = al;
    li->qtd++;
    return 1;
};

int insereListaInicio(Lista* li, struct aluno al){
    if(li == NULL){
        return 0;
    }
    if(listaCheia(li)){
        return 0;
    }
    int i;
    for(i = li->qtd-1; i >= 0; i--){
        li->dados[i+1] = li->dados[i];
    }
    li->dados[0] = al;
    li->qtd++;
    return 1;
}

int insereListaOrdenada(Lista* li,struct aluno al){
    if(li == NULL){
        return 0;
    }
    if(listaCheia(li)){
        return 0;
    }
    int k,i = 0;
    while(i < li->qtd && li->dados[i].matricula < al.matricula){
        i++;
    }
    for(k = li->qtd-1; k >= i; k--){
        li->dados[k+1] = li->dados[k];
    }
    li->dados[i] = al;
    li->qtd++;
    return 1;
}

int removerListaFinal(Lista* li){
    if(li == NULL){
        return 0;
    }
    if(li->qtd == 0){
        return 0;
    }
    li->qtd--;
    return 1;
}

int removerListaInicio(Lista* li){
    if(li == NULL){
        return 0;
    }
    if(li->qtd == 0){
        return 0;
    }
    int k = 0;
    for(k = 0 ; k < li->qtd-1; k++){
        li->dados[k] = li->dados[k+1];
    }
    li->qtd--;
    return 1;
}

int removerLista(Lista* li, int mat){
    if(li == NULL) return 0;
    if(li->qtd == 0) return 0;

    int k,i = 0;
    while( i < li->qtd && li->dados[i].matricula != mat)
        i++;
    if(i == li->qtd)
        return 0;

    for(k = i; k < li->qtd-1; k++){
        li->dados[k] = li->dados[k+1];
    }
    li->qtd--;
    return 1;
}

int consultaListaPos(Lista* li, int pos, struct aluno al){
    if(li == NULL || pos <= 0 || pos < li->qtd)
        return 0;
    al = li->dados[pos-1];
    return 1;
}

int consultaListaMat(Lista* li, int mat, struct aluno al){
    if(li == NULL)
        return 0;
    int i,k = 0;
    while( i < li->qtd || li->dados[i].matricula != mat)
        i++;
    if(i == li->qtd)
        return 0;
    al = li->dados[i];
    return 1;
}