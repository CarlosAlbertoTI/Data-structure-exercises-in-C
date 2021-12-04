#include <stdio.h>
#include <stdlib.h>
#include "deck.h"

struct deck
{
    int inicio, fim, quantidade;
    struct aluno dados[MAX];
};

Deck *criar_deck()
{
    Deck *deck;
    deck = (Deck *)malloc(sizeof(Deck));
    if (deck != NULL)
    {
        deck->inicio = 0;
        deck->fim = 0;
        deck->quantidade = 0;
    }
    return deck;
}

void liberaDeck(Deck *deck)
{
    free(deck);
}

int tamanhoDeck(Deck *deck)
{
    if (deck == NULL)
    {
        return 0;
    }
    return deck->quantidade;
}

int deckVazio(Deck *deck)
{
    if (deck == NULL)
    {
        return -1;
    }
    if (deck->quantidade == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int deckCheio(Deck *deck)
{
    if (deck == NULL)
    {
        return -1;
    }
    if (deck->quantidade == MAX)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int consultaDeck(Deck *deck, struct aluno *al)
{
    if (deck == NULL || deck->quantidade == 0)
    {
        return 0;
    }
    *al = deck->dados[deck->inicio];
    return 1;
}

int consultaFinalDeck(Deck *deck, struct aluno *al)
{
    if (deck == NULL || deck->quantidade == 0)
    {
        return 0;
    }
    int pos = deck->fim - 1;
    if (pos < 0)
    {
        pos = MAX - 1;
    }
    *al = deck->dados[pos];
    return 1;
}

int inserirInicioDeck(Deck *deck, struct aluno al)
{
    if (deck == NULL || deck->quantidade == MAX)
    {
        return 0;
    }

    deck->inicio--;
    if (deck->inicio < 0)
        deck->inicio = MAX - 1;
    deck->dados[deck->inicio] = al;
    deck->quantidade++;
    return 1;
}

int inserirFimDeck(Deck *deck, struct aluno al)
{
    if (deck == NULL || deck->quantidade == MAX)
    {
        return 0;
    }

    deck->dados[deck->fim] = al;
    deck->fim = (deck->fim + 1) % MAX;
    deck->quantidade++;
    return 1;
}

int removeInicio(Deck* deck){
    if (deck == NULL || deck->quantidade == 0)
    {
        return 0;
    }

    deck->inicio = (deck->inicio+1)%MAX;
    deck->quantidade--;
    return 1;
}


int removeFim(Deck* deck){
    if (deck == NULL || deck->quantidade == 0)
    {
        return 0;
    }

    deck->fim--;
    if(deck->fim < 0){
        deck->fim = MAX -1;
    }
    deck->quantidade--;
    return 1;
}