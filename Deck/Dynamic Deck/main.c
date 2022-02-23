#include <stdio.h>
#include <stdlib.h>
#include "DDeck.h"


int main(){

    al aluno1;
    al busca_al1;

    al aluno2;
    al busca_al2;

    Deck* deck;
    deck = criar_deck();



    int x1 = inserir_inicio(deck,aluno1);
    int x2 = inserir_final(deck,aluno2);
    printf("inserir: %i - %i\n",x1,x2);

    int isEmpty = vazio_deck(deck);
    if(isEmpty != 0){
        printf("vazio: %i\n",isEmpty);
    }

    int x = consulta_inicio(deck,&busca_al1);
    if(x != 0){
        printf("consulta inicio: %i\n",x);
    }

    int y = consulta_fim(deck,&busca_al2);
    if(y != 0){
        printf("consulta fim: %i\n",y);
    }

    int y1 = remover_inicio(deck);
    int y2 = remover_final(deck);
    printf("remover: %i - %i\n",y1,y2);


    int size = tam_deck(deck);
    printf("tam: %i\n",size);

    liberar_deck(deck);
    return 0;
}
