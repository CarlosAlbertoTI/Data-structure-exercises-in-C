#include <stdio.h>
#include <stdlib.h>
#include "priorityQueue.h"

int main(){
    PQueue* pqueue = create_PQueue();
    char teste[10];
    int insert1 = insert_PQueue(pqueue, "Carlos", 10);
    printf("Insert1: %i\n", insert1);

    int insert2 = insert_PQueue(pqueue, "andre", 6);
    printf("Insert2: %i\n", insert2);

    int search1 = search_PQueue(pqueue, teste);
    printf("Search1: %i\n", search1);

    int remove1 = remove_PQueue(pqueue);
    printf("Remove1: %i\n", remove1);

    return 1;
}