#include <stdio.h>
#include <stdlib.h>
#include "DDeck.h"

struct elemento {
    struct elemento *ante;
    struct aluno al;
    struct elemento *prox;
};

typedef struct elemento node;


struct DDeck {
    struct elemento *inicio;
    struct elemento *fim;
    int quantd;
};



Deck* criar_deck(){
    Deck* deck = (Deck*)malloc( sizeof(Deck));
    if(deck != NULL){
        deck->inicio = NULL;
        deck->fim = NULL;
        deck->quantd = 0;
    }
    return deck;
}

void liberar_deck(Deck* deck){
    if(deck != NULL){
        node* no = deck->inicio;
        while(deck->inicio != NULL){
            no = deck->inicio;
            deck->inicio = deck->inicio->prox;
            free(no);
        }
        free(deck);
    }

}

int tam_deck(Deck* deck){
    if(deck != NULL){
        return deck->quantd;
    }
    return 0;
}

int vazio_deck(Deck* deck){
    if(deck == NULL){
        return 1;
    }
    if(deck->inicio == NULL){
        return 1;
    }
    return 0;
}

int consulta_inicio(Deck* deck, struct aluno *al){
    if(deck == NULL){
        return 0;
    }
    if(deck->inicio == NULL){
        return 0;
    }
    *al = deck->inicio->al;
    return 1;
}

int consulta_fim(Deck* deck, struct aluno *al){
     if(deck == NULL){
        return 0;
    }
    if(deck->inicio == NULL){
        return 0;
    }
    *al = deck->fim->al;
    return 1;
}

int inserir_inicio(Deck* deck, struct aluno al){
    if(deck == NULL) return 0;
    node  *no = (node*) malloc(sizeof(node));
    if(no == NULL) return 0;
    no->al = al;
    no->prox = deck->inicio;
    no->ante = NULL;
    if(deck->inicio == NULL){
        deck->fim = no;
    }else{
        deck->inicio->ante = no;
    }
    deck->inicio = no;
    deck->quantd++;
    return 1;
}


int inserir_final(Deck* deck, struct aluno al){
    if(deck == NULL) return 0;
    node  *no = (node*) malloc(sizeof(node));
    if(no == NULL) return 0;
    no->al = al;
    no->prox = NULL;
    if(deck->fim == NULL){
        no->ante = NULL;
        deck->inicio = no;
    }else{
        no->ante = deck->fim;
        deck->fim->prox = no;
    }
    deck->fim = no;
    deck->quantd++;
    return 1;  
}

int remover_inicio(Deck* deck){
    if(deck == NULL) return 0;
    if(deck->inicio == NULL) return 0;
    node  *no = deck->inicio;
    deck->inicio = deck->inicio->prox;
    if(deck->inicio == NULL){
        deck->fim = NULL;
    }else{
        deck->inicio->ante = NULL;
    }
    free(no);
    deck->quantd--;
    return 1;

} 

int remover_final(Deck* deck){
    if(deck == NULL) return 0;
    if(deck->inicio == NULL) return 0;
    node  *no = deck->fim;
    if(no == deck->inicio){
        deck->inicio = NULL;
        deck->fim = NULL;

    }else{
        no->ante->prox = NULL;
        deck->fim = no->ante;
    }
    free(no);
    deck->quantd--;
    return 1;
}