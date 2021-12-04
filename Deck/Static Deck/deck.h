#define MAX 100

struct aluno{
    int matricula;
    char nome[10];
    float n1,n2,n3;
};
typedef struct deck Deck;

Deck* criar_deck();
void liberaDeck(Deck* deck);
int tamanhoDeck(Deck* deck);
int deckVazio(Deck* deck);
int deckCheio(Deck* deck);
int consultaDeck(Deck* deck, struct aluno *al);
int consultaFinalDeck(Deck* deck, struct aluno *al);
int inserirInicioDeck(Deck* deck, struct aluno al);
int inserirFimDeck(Deck* deck, struct aluno al);
int removeInicio(Deck* deck);
int removeFim(Deck* deck);