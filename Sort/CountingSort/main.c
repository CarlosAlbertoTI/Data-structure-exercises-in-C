#include <stdio.h>
#include <stdlib.h>
#define MAX 100
void countingSort(int* V, int N){
    int i, j, k;
    int baldes[MAX];
    for(i = 0; i <MAX; i++){
        baldes[i] = 0;
    }

    for (i = 0; i < N; i++)
    {
        baldes[V[i]]++;
    }

    for(int i = 0, j = 0; j < MAX; j++)
        for(k = baldes[j]; k > 0; k--)
            V[i++] = j;
    

}

int main(){
    int vetor[10] = {2, 12, 10, 3, 5, 1, 5, 22,9, 0};
    countingSort(vetor,10);
    for (int i = 0; i < 10; i++)
    {
        printf("%i ",vetor[i]);
    }
    


    return 0;
}