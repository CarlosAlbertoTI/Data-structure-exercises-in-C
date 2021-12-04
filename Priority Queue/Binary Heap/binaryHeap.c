#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binaryHeap.h"

struct Patient {
    char name[30];
    int priority;
};

struct PriorityQueue {
    int amount;
    struct Patient data[MAX];
};

PQueue* create_PQueue(){
    PQueue* pqueue;
    pqueue = (PQueue*) malloc(sizeof(PQueue));
    if(pqueue != NULL){
        pqueue->amount = 0;
    }
    return pqueue; 
}

void free_PQueue(PQueue* pqueue){
    free(pqueue);
}


int search_PQueue(PQueue* pqueue, char * name){
    if(pqueue == NULL || pqueue->amount == 0) return 0;
    strcpy(name, pqueue->data[pqueue->amount-1].name);
    return 1;
}

void fixElement(PQueue* pqueue, int child){
    int father;
    struct Patient temp;
    father =  ( child - 1 ) /2;
    while( (child > 0) && (pqueue->data[father].priority <= pqueue->data[child].priority)){

        temp = pqueue->data[child];
        pqueue->data[child] = pqueue->data[father];
        pqueue->data[father] = temp;

        child = father;
        father = (father -1 )/2;
    }
}  

int insert_PQueue(PQueue* pqueue, char* name, int priority){
    if(pqueue == NULL) return 0;
    if(pqueue->amount == MAX) return 0;

    strcpy(pqueue->data[pqueue->amount].name,name);
    pqueue->data[pqueue->amount].priority = priority;
    fixElement(pqueue, pqueue->amount);
    pqueue->amount++;
    return 1;
}

void setDownElement(PQueue* pqueue, int father){
    struct Patient temp;
    int son = 2 * father + 1;
    while(son < pqueue->amount){

        if(son < pqueue->amount-1){
            if(pqueue->data[son].priority < pqueue->data[son+1].priority){
                son++;
            }
        }

        if(pqueue->data[father].priority >= pqueue->data[son].priority){
            break;
        }

        temp = pqueue->data[father];
        pqueue->data[father] = pqueue->data[son];
        pqueue->data[son] = temp;

        father = son;
        son = 2 * father  + 1;
    }
}

int remove_PQueue(PQueue* pqueue){
    if(pqueue == NULL) return 0;
    if(pqueue->amount == 0) return 0;

    pqueue->amount--;
    pqueue->data[0] = pqueue->data[pqueue->amount];
    setDownElement(pqueue, 0);
    return 1;
}