#include <stdio.h>
#include <stdlib.h>
#include "arvoreAVL.h"

ArvrAVL* cria_arvoreAVL(){
    ArvrAVL* raiz = (ArvrAVL*) malloc(sizeof(ArvrAVL));
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

void libera_ArvAVL(ArvrAVL* raiz){
    if(raiz == NULL){
        return;
    }
    liberaNo(*raiz);
    free(raiz);
}

void preOrdem_ArvoreAVL(ArvrAVL *raiz){
    if(raiz == NULL) return;
    if(*raiz != NULL){
        printf("%d\n", (*raiz)->info);
        preOrdem_ArvoreAVL(&(*raiz)->esquerda);
        preOrdem_ArvoreAVL(&(*raiz)->direita);
    }
}

void emOrdem_ArvoreAVL(ArvrAVL *raiz){
    if(raiz == NULL) return;
    if(*raiz != NULL){
        preOrdem_ArvoreAVL(&(*raiz)->esquerda);
        printf("%d\n", (*raiz)->info);
        preOrdem_ArvoreAVL(&(*raiz)->direita);
    }

}

void posOrdem_ArvoreAVL(ArvrAVL *raiz){
    if(raiz == NULL) return;
    if(*raiz != NULL){
        preOrdem_ArvoreAVL(&(*raiz)->esquerda);
        preOrdem_ArvoreAVL(&(*raiz)->direita);
        printf("%d\n", (*raiz)->info);
    }

}

int estaVazia_ArvoreAVL(ArvrAVL *raiz){
    if(raiz == NULL) return 1;
    if((*raiz) == NULL) return 1;
    return 0;
}

int altura_NO(struct NO* no){
    if(no == NULL){
        return -1;
    }else{
        return no->altura; 
    }
}

int fatorBalanceamento_NO(struct NO* no){
    return labs(altura_NO(no->esquerda) - altura_NO(no->direita));
}

int maior(int x, int y){
    if(x > y) {
        return x;
    }else{
        return y;
    }
}

void rotacaoLL(ArvrAVL *raiz){
    struct NO *no;
    
    no = (*raiz)->esquerda;
    (*raiz)->esquerda = no->direita;
    no->direita = (*raiz);

    (*raiz)->altura = maior(altura_NO((*raiz)->esquerda),altura_NO((*raiz)->direita)) + 1;
    no->altura = maior(altura_NO(no->esquerda), (*raiz)->altura) + 1; 

    (*raiz) = no;
}

void rotacaoRR(ArvrAVL *raiz){
    struct NO *no;
    
    no = (*raiz)->direita;
    (*raiz)->direita = no->esquerda;
    no->esquerda = (*raiz);

    (*raiz)->altura = maior(altura_NO((*raiz)->esquerda),altura_NO((*raiz)->direita)) + 1;
    no->altura = maior(altura_NO(no->direita), (*raiz)->altura) + 1; 

    (*raiz) = no;
}

void rotacaoLR(ArvrAVL *raiz){
    rotacaoRR(&(*raiz)->esquerda);
    rotacaoLL(raiz);
}

void rotacaoRL(ArvrAVL *raiz){
    rotacaoLL(&(*raiz)->direita);
    rotacaoRR(raiz);
}

int inserir_arvAVL(ArvrAVL *raiz, int valor){
    int res;
    if((*raiz) == NULL){
        
        struct NO *novo;
        novo = (struct NO*) malloc(sizeof(struct NO));
        if(novo == NULL)
            return 0;

        novo->info = valor;
        novo->altura = 0;
        novo->direita = NULL;
        novo->esquerda = NULL;

        (*raiz) = novo;
        return 1;
    }

    struct NO *atual = (*raiz);
    if(valor  < atual->info){
        if((res = inserir_arvAVL(&(*raiz)->esquerda, valor)) == 1){
            if(fatorBalanceamento_NO(atual) >= 2){
                if(valor < (*raiz)->esquerda->info){
                    rotacaoLL(raiz);
                }else{
                    rotacaoLR(raiz);
                }
            }
        }
    }else{
        if(valor > atual->info){
            if((res = inserir_arvAVL(&(*raiz)->direita, valor)) == 1){
                if(fatorBalanceamento_NO(atual) >= 2){
                    if(valor > (*raiz)->direita->info){
                        rotacaoRR(raiz);
                    }else{
                        rotacaoRL(raiz);
                    }
                }
            }
        }else{
            printf("Valor duplicado!!");
        }
    }

    atual->altura = maior(altura_NO(atual->esquerda),altura_NO(atual->direita))+1;
    return res;

}

struct NO* procurarMenor(struct NO* atual){
    struct NO *no1 = atual;
    struct NO *no2 = atual->esquerda;

    while(no2 != NULL){
        no1 = no2;
        no2 = no2->esquerda;
    }
    return no1;
}

int remover_arvAVL(ArvrAVL *raiz, int valor){
    if((*raiz) == NULL){
        printf("Valor não existe!\n");
        return 0;
    }
    int res;
    if(valor < (*raiz)->info){
        if((res = remover_arvAVL(&(*raiz)->esquerda, valor)) == 1){
            if(fatorBalanceamento_NO(*raiz) >= 2){
                if(altura_NO((*raiz)->direita->esquerda) <= altura_NO((*raiz)->direita->direita)){
                    rotacaoRR(raiz);
                }else{
                    rotacaoRL(raiz);
                }
            }
        }
    }
    if((*raiz)->info < valor){
        if((res = remover_arvAVL(&(*raiz)->direita, valor)) == 1){
            if(fatorBalanceamento_NO(*raiz) >= 2){
                if(altura_NO((*raiz)->esquerda->direita) <= altura_NO((*raiz)->esquerda->esquerda)){
                    rotacaoLL(raiz);
                }else{
                    rotacaoLR(raiz);
                }
            }
        }
    }

    if((*raiz)->info == valor){
        if((*raiz)->esquerda == NULL || (*raiz)->direita == NULL){
            struct NO* oldNode = (*raiz);
            if((*raiz)->direita == NULL){
                (*raiz) = (*raiz)->esquerda;
            }else{
                (*raiz) = (*raiz)->direita;
            }
            free(oldNode);
        }else{
            struct NO* temp = procurarMenor((*raiz)->direita);
            (*raiz)->info = temp->info;
            remover_arvAVL(&(*raiz)->direita, (*raiz)->info);
            if(fatorBalanceamento_NO(*raiz) >= 2){
                if(altura_NO((*raiz)->esquerda->direita) <= altura_NO((*raiz)->esquerda->esquerda)){
                    rotacaoLL(raiz);
                }else{
                    rotacaoLR(raiz);
                }
            }
        }
        return 1;
    }
    return res;
    
}