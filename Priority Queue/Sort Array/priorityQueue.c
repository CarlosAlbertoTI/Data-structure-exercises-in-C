#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "priorityQueue.h"

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

int search_PQueue(PQueue* pqueue, char* name){
    if(pqueue == NULL || pqueue->amount == 0) return 0;
    strcpy(name, pqueue->data[pqueue->amount-1].name);
    return 1;
}

int insert_PQueue(PQueue* pqueue, char* name, int priority){
    if(pqueue == NULL) return 0;
    if(pqueue->amount == MAX) return 0;

    int i = pqueue->amount -1;
    while(i >= 0 && pqueue->data[i].priority >= priority){
        pqueue->data[i+1] = pqueue->data[i];
        i--;
    }

    strcpy(pqueue->data[i+1].name, name);
    pqueue->data[i+1].priority = priority;
    pqueue->amount++;
    return 1;
}

int remove_PQueue(PQueue* pqueue){
    if(pqueue == NULL) return 0;
    if(pqueue->amount == 0) return 0;
    pqueue->amount--;
    return 1;
}

// int size_PQueue(PQueue* Pqueue);
// int isFull_PQueue(PQueue* Pqueue);
// int isEmpty_PQueue(PQueue* Pqueue);