#define MAX 100

struct aluno{
    int matricula;
    char nome[10];
    float n1,n2,n3;
};
typedef struct aluno al;
typedef struct DDeck Deck;

Deck* criar_deck();

void liberar_deck(Deck* deck);
int tam_deck(Deck* deck);
int vazio_deck(Deck* deck);

int consulta_inicio(Deck* deck, struct aluno *al);
int consulta_fim(Deck* deck, struct aluno *al);

int inserir_inicio(Deck* deck, struct aluno al);
int inserir_final(Deck* deck, struct aluno al);

int remover_inicio(Deck* deck);
int remover_final(Deck* deck);



