#include "stdio.h"
#include "stdlib.h"
#include "Bag.h"

struct NO{
  int valor;
  struct NO* prox;
};

struct descritor {
  struct NO* inicio;
  int qnt;
  struct NO* iterador;
};

Bag* criarBag(){
  Bag* b = (Bag*) malloc(sizeof(Bag));
  if(b != NULL){
    b->inicio = NULL;
    b->iterador = NULL;
    b->qnt = 0; 
  }

  return b;  
}

void liberaBag(Bag* bag){
  if(bag != NULL){
    struct NO* aux;
    while(bag->inicio != NULL){
      aux = bag->inicio;
      bag->inicio = bag->inicio->prox;
      free(aux);      
    }
    free(bag);
  }
}

int insereBag(Bag* bag, int valor){
  if(bag == NULL) return 0;
  struct NO* aux;
  aux = (struct NO*) malloc(sizeof(struct NO));
  if(aux == NULL) return 0;
  aux->valor = valor;
  aux->prox = bag->inicio;
  bag->inicio = aux;
  bag->qnt++;
  return 1;
}

int removerBag(Bag* bag, int valor){
  if(bag == NULL) return 0;
  int cont = 0;
  struct NO* ante;
  struct NO* no = bag->inicio;
  while(no != NULL){
    if(no->valor == valor){
      cont++;
      if(bag->inicio->valor == valor){
          bag->inicio = no->prox;
          free(no);
          no = bag->inicio;
      }else{
        ante->prox = no->prox;
        free(no);
        no = ante->prox;
      }
    }else{
      ante = no;
      no = no->prox;
    }
  }
  bag->qnt = bag->qnt - cont;
  return cont;
}

int buscaBag(Bag* bag, int valor){
  if(bag == NULL) return 0;
  struct NO* no = bag->inicio;
  int count = 0;
  while(no != NULL){
    if(no->valor == valor)
      count++;
    no = no->prox;
  }
  return count;
}


void beginBag(Bag* Bag){
 if(Bag == NULL) return;
  Bag->iterador = NULL;
  Bag->iterador  = Bag->inicio;  
}

int endBag(Bag* Bag){
  if(Bag == NULL) return 1;
  if(Bag->iterador == NULL) {return 1;}
  else{
     return 0;}
}

void nextBag(Bag* Bag){
  if(Bag == NULL) return;
  if(Bag->iterador != NULL){
    Bag->iterador = Bag->iterador->prox;
  }
}

void getItemBag(Bag* Bag, int * num){
  if(Bag == NULL) return;
  if(Bag->iterador != NULL){
    *num = Bag->iterador->valor;
  }
}