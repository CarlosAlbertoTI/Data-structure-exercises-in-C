#include <stdio.h>
#include <stdlib.h>
#include "SkipList.h"

struct Node {
    int chave;
    struct Node ** prox;
};

struct SkipList{
    int nivelMaX;
    float p;
    int nivel;
    struct Node *inicio;
};

struct Node* novoNode(int chave, int nivel){
    struct Node* node = malloc(sizeof(struct Node));
    if(node != NULL){
        node->chave = chave;
        node->prox = malloc((nivel+1) * sizeof(struct Node*));
        
        int i;
        for ( i = 0; i < (nivel+1); i++){
            node->prox[i] = NULL;
        }
    }
    return node;
}

SkipList* criar_skipList(int MAXLVL, float p){
    SkipList *sk = (SkipList*) malloc(sizeof(SkipList));
    if(sk != NULL){
        sk->nivelMaX = MAXLVL;
        sk->p = p;
        sk->nivel = 0;
        sk->inicio = novoNode(-1, MAXLVL);
    }

    return sk;
}

void liberarSkipList(SkipList* skipList){
    if(skipList == NULL) return;

    struct Node *no, * atual;
    atual = skipList->inicio->prox[0];
    while(atual != NULL){
        no = atual;
        atual = atual->prox[0];
        free(no->prox);
        free(no);
    }

    free(skipList->inicio);
    free(skipList);
}

int buscar_skipList(SkipList* skipList, int chave){
    if(skipList == NULL) return 0;

    struct Node *atual = skipList->inicio;

    int i;
    for ( i = skipList->nivel; i > 0; i--){
        while(atual->prox[i] != NULL && atual->prox[i]->chave < chave){
            atual = atual->prox[i];
        }
    }

    atual = atual->prox[0];
    if(atual != NULL && atual->chave == chave){
        return 1;
    }else{
        return 0;
    }
    
}


int sorteiaNivel(SkipList * skipList){
    float r = (float) rand()/RAND_MAX;
    int nivel = 0;
    while(r < skipList->p && nivel < skipList->nivelMaX){
        nivel++;
        r = (float) rand()/RAND_MAX;
    }
    return nivel;
}

int inserir_skipList(SkipList* skipList, int chave){
    if(skipList == NULL) return 0;

    int i;
    struct Node * atual = skipList->inicio;

    struct Node ** aux;
    aux = malloc((skipList->nivelMaX+1) * sizeof(struct Node*));
    for ( i = 0; i <= skipList->nivelMaX; i++){
        aux[i] = NULL;
    }


    for ( i = skipList->nivel; i >= 0; i--){
        while(atual->prox[i] != NULL && atual->prox[i]->chave < chave){
            atual = atual->prox[i];
        }
        aux[i] = atual;
    }

    atual = atual->prox[0];
    
    if(atual == NULL || atual->chave != chave){
        
        int novo_nivel = sorteiaNivel(skipList);

        struct Node* novo = novoNode(chave, novo_nivel);
        if(novo == NULL){
            free(aux);
            return 0;
        }

        if(novo_nivel > skipList->nivel){
            for ( i = skipList->nivel+1; i <= novo_nivel; i++){
                aux[i] = skipList->inicio;
            }
            skipList->nivel = novo_nivel;    
        }

        for ( i = 0; i <= novo_nivel; i++){
            novo->prox[i] = aux[i]->prox[i];
            aux[i]->prox[i] = novo;
        }
        free(aux);
        return 1;
    }

}

int remove_skipList(SkipList* skipList, int chave){
    if(skipList == NULL) return 0;

    int i;
    struct Node * atual = skipList->inicio;

    struct Node ** aux;
    aux = malloc((skipList->nivelMaX+1) * sizeof(struct Node*));
    for ( i = 0; i <= skipList->nivelMaX; i++){
        aux[i] = NULL;
    }


    for ( i = skipList->nivel; i >= 0; i--){
        while(atual->prox[i] != NULL && atual->prox[i]->chave < chave){
            atual = atual->prox[i];
        }
        aux[i] = atual;
    }

    atual = atual->prox[0];

    if(atual == NULL || atual->chave == chave){
        for(i = 0; i <= skipList->nivel; i++){
            if(aux[i]->prox[i] != atual){
                break;
            }
            aux[i]->prox[i] = atual->prox[i];
        }

        while(skipList->nivel > 0 && skipList->inicio->prox[skipList->nivel] == NULL){
            skipList->nivel--;
        }

        free(atual->prox);
        free(atual);
        free(aux);
        return 1;
    }

    free(aux);
    return 0;

}