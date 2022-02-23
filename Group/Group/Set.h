#include <stdio.h>
#include <stdlib.h>
#include "arvoreAVL.h"

typedef struct sett {
    ArvrAVL* arv;
    int qntd;
    struct iterator *iter;
}Sett;

Sett* criarSett();
void liberaSett(Sett* set);

int inserirSet(Sett *set, int num);
int removerSet(Sett *set, int num);
int consultaSet(Sett * set, int num);

void beginSet(Sett* set);
int endSet(Sett* set);
void nextSet(Sett* set);
void getItemSet(Sett* set, int * num);

Sett* uniaoSet(Sett* A,Sett* B);
Sett* intersecaoSet(Sett* A,Sett* B);