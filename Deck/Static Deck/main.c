#include <stdio.h>
#include <stdlib.h>
#include "deck.h"


int main(){
    Deck* deck = criar_deck();
    struct aluno a1;
    struct aluno a2;
    struct aluno a3;
    struct aluno a4;

    int vazio = deckVazio(deck);

    int inserir1 = inserirInicioDeck(deck, a1);
    int inserir2 = inserirFimDeck(deck, a2);

    int tamD = tamanhoDeck(deck);
    int x = consultaDeck(deck, &a3);
    int y = consultaFinalDeck(deck, &a4);

    liberaDeck(deck);

    return 0;
}