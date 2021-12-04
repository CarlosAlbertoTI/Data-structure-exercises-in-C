#define MAX 100

typedef struct PriorityQueue PQueue;

PQueue* create_PQueue();
void free_PQueue(PQueue* Pqueue);

int search_PQueue(PQueue* Pqueue, char * name);
int insert_PQueue(PQueue* Pqueue, char* name, int priority);
int remove_PQueue(PQueue* Pqueue);
// int size_PQueue(PQueue* Pqueue);
// int isFull_PQueue(PQueue* Pqueue);
// int isEmpty_PQueue(PQueue* Pqueue);