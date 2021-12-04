#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

ArvBinaria* cria_arvoreB(){
    ArvBinaria* raiz = (ArvBinaria*) malloc(sizeof(ArvBinaria));
    if(raiz != NULL){
        *raiz = NULL;
    } 

    return raiz;
}

void liberaNo(struct NO* no){
    if(no == NULL) return;
    liberaNo(no->esquerda);
    liberaNo(no->direita);
    free(no); 
    no = NULL;   
}

void libera_ArvBin(ArvBinaria* raiz){
    if(raiz == NULL){
        return;
    }
    liberaNo(*raiz);
    free(raiz);
}

int estaVazia_ArvoreB(ArvBinaria *raiz){
    if(raiz == NULL) return 1;
    if((*raiz) == NULL) return 1;
    return 0;
}

int altura_arvoreB(ArvBinaria *raiz){
    if(raiz == NULL) return 0;
    if((*raiz) == NULL) return 0;

    int alt_esquerda = altura_arvoreB(&((*raiz)->esquerda));
    int alt_direita = altura_arvoreB(&((*raiz)->direita));
    
    if(alt_esquerda > alt_direita){
        return (alt_esquerda +1);
    }else{
        return (alt_direita +1);

    }
}

int total_NO_arvoreB(ArvBinaria *raiz){
    if(raiz == NULL) return 0;
    if((*raiz) == NULL) return 0;

    int alt_esquerda = total_NO_arvoreB(&((*raiz)->esquerda));
    int alt_direita = total_NO_arvoreB(&((*raiz)->direita));

    return (alt_direita + alt_esquerda +1);
}

void preOrdem_ArvoreB(ArvBinaria *raiz){
    if(raiz == NULL) return;
    if(*raiz != NULL){
        printf("%d\n", (*raiz)->info);
        preOrdem_ArvoreB(&(*raiz)->esquerda);
        preOrdem_ArvoreB(&(*raiz)->direita);
    }
}

void emOrdem_ArvoreB(ArvBinaria *raiz){
    if(raiz == NULL) return;
    if(*raiz != NULL){
        preOrdem_ArvoreB(&(*raiz)->esquerda);
        printf("%d\n", (*raiz)->info);
        preOrdem_ArvoreB(&(*raiz)->direita);
    }

}

void posOrdem_ArvoreB(ArvBinaria *raiz){
    if(raiz == NULL) return;
    if(*raiz != NULL){
        preOrdem_ArvoreB(&(*raiz)->esquerda);
        preOrdem_ArvoreB(&(*raiz)->direita);
        printf("%d\n", (*raiz)->info);
    }

}

int inserir_ArvoreB(ArvBinaria *raiz, int valor){
    if(raiz == NULL) return 0;
    
    struct NO* novo;
    novo = (struct NO*) malloc(sizeof(struct NO));
    if(novo == NULL) return 0;

    novo->info = valor;
    novo->direita = NULL;
    novo->esquerda = NULL;

    if((*raiz) == NULL){
        (*raiz) = novo;
    }else{

        struct NO* atual = (*raiz);
        struct NO* anterior = NULL;

        while(atual != NULL){
            anterior = atual;
            if(atual->info == valor){
                free(novo);
                return 0;
            }

            if(valor > atual->info){
                atual = atual->direita;
            }else{
                atual = atual->esquerda;
            }
  
        }

        if(valor > anterior->info){
            anterior->direita = novo;
        }else{
            anterior->esquerda = novo;
        }
    }
        return 1;
}

struct NO* remove_atual(struct NO* atual){
    struct NO *no1, *no2;
    if(atual->esquerda == NULL){
        no2 = atual->direita;
        free(atual);
        return no2;
    }

    no1 = atual;
    no2 = atual->esquerda;
    while(no2->direita != NULL){
        no1 = no2;
        no2 = no2->direita;
    }

    if(no1 != atual){
        no1->direita = no2->esquerda;
        no2->esquerda = atual->esquerda;
    }

    no2->direita = atual->direita;
    free(atual);
    return no2;
}

int remove_ArvoreB(ArvBinaria *raiz, int valor){
    if(raiz == NULL) return 0;

    struct NO* atual = (*raiz);
    struct NO* anterior = NULL;

    while(atual != NULL){
        if(atual->info == valor){
            if(atual == (*raiz)){
                (*raiz) = remove_atual(atual);       
            }else{
                
                if(anterior->direita == atual){
                    anterior->direita = remove_atual(atual);
                }else{
                    anterior->esquerda = remove_atual(atual);
                }
            }
            return 1;
        }
        
        anterior = atual;
        if(valor > atual->info){
            atual = atual->direita;
        }else{
            atual = atual->esquerda;
        }
    
    }
    return 0;
}

int consulta_ArvoreB(ArvBinaria *raiz, int valor){
    if(raiz == NULL) return 0;
    struct NO* atual = (*raiz);
    while(atual != NULL){
        if(valor == atual->info){
            return 1;
        }
        if(valor > atual->info){
            atual = atual->direita;
        }else{
            atual = atual->esquerda;
        }
    }
    return 0;
}