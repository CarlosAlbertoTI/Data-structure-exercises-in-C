#include <stdio.h>
#include <stdlib.h>
#include "Set.h"

Sett* criarSett(){
    Sett* s = (Sett*) malloc(sizeof(Sett));
    if(s != NULL){
        s->arv = cria_arvoreAVL();
        s->qntd = 0;
        s->iter = NULL;
    }
    return s;
}

void liberaSett(Sett* sett){
    if(sett != NULL){
        libera_ArvAVL(sett->arv);

        struct iterator * no;
        while(sett->iter != NULL){
            no = sett->iter;
            sett->iter = sett->iter->prox;
            free(no);
        }
        free(sett);
    }
}

int inserirSet(Sett *set, int num){
  if(set == NULL) return 0;
  if(inserir_arvAVL(set->arv,num) == 1){
    set->qntd++;
    return 1;
  }
  return 0; 
}

int removerSet(Sett *set, int num){
  if(set == NULL) return 0;
  if(remover_arvAVL(set->arv,num) == 1){
    set->qntd--;
    return 1;
  }
  return 0; 
}

int consultaSet(Sett * set, int num){
  if(set == NULL) return 0;
  return consulta_arvAVL(set->arv, num);
}

void beginSet(Sett* set){
 if(set == NULL) return;
  set->iter = NULL;
  iterator_ArvAVL(set->arv, &(set->iter));
}

int endSet(Sett* set){
  if(set == NULL) return 1;
  if(set->iter == NULL) {return 1;}
  else{
     return 0;}
}

void nextSet(Sett* set){
  if(set == NULL) return;
  if(set->iter != NULL){
    struct iterator *no = set->iter;
    set->iter = set->iter->prox;
    free(no);
  }
}

void getItemSet(Sett* set, int * num){
  if(set == NULL) return;
  if(set->iter != NULL){
    *num = set->iter->valor;
  }
}

Sett* uniaoSet(Sett* A,Sett* B){
  if(A == NULL || B == NULL) return NULL;
  int x;
  Sett* C = criarSett();

  for(beginSet(A);!endSet(A); nextSet(A)){
    getItemSet(A, &x);
    inserirSet(C, x);
  }

  for(beginSet(B);!endSet(B); nextSet(B)){
    getItemSet(B, &x);
    inserirSet(C, x);
  }

  return C;
}

Sett* intersecaoSet(Sett* A,Sett* B){
  if(A == NULL || B == NULL) return NULL;
  int x;
  Sett* C = criarSett();

  if(A->qntd < B->qntd){
    for(beginSet(A);!endSet(A); nextSet(A)){
      getItemSet(A, &x);
      if(consultaSet(B, x)) inserirSet(C, x);
    }
  }else{
    for(beginSet(B);!endSet(B); nextSet(B)){
      getItemSet(B, &x);
      if(consultaSet(A, x)) inserirSet(C, x);
    }
  }
  return C;
}



