#include <stdio.h>
#include <stdlib.h>

#define TAM 5

struct balde {
    int qntd;
    int valores[TAM];
}; 

void insertion_sort(int *v, int N){
    int i, j, aux;
    for(i = 0; i < N; i++){
        aux = v[i];
        for(j = i; (j > 0) && (aux < v[j - 1]); j--){
            v[j] = v[j - 1];
        }   
        v[j] = aux;
    }
}

void bucketSort(int * V, int N){
    int i, j, maior, menor, numBaldes, pos;
    struct balde *bd;

    maior = menor = V[0];
    for ( i = 0; i < N; i++)
    {
        if(V[i] > maior) maior = V[i];
        if(V[i] < menor) menor = V[i];
    }


    numBaldes = (maior - menor) / TAM + 1;
    bd = (struct balde *) malloc(numBaldes * sizeof(struct balde));
    for ( i = 0; i < numBaldes; i++)
    {
        bd->qntd = 0;
    }

    for ( i = 0; i < N; i++)
    {
        pos = (V[i] - menor) / TAM;
        bd[pos].valores[bd[pos].qntd] = V[i];
        bd[pos].qntd++;
    }

    pos = 0;
    for ( i = 0; i < numBaldes; i++)
    {
        insertion_sort(bd[i].valores, bd[i].qntd);
        for ( j = 0; j < bd[i].qntd; j++)
        {
            V[pos] = bd[i].valores[j];
            pos++;
        }
    }
    free(bd);
}


int main()
{
    int vetor[10] = {2, 12, 10, 3, 5, 1, 5, 22,9, 0};
    bucketSort(vetor,10);
    for (int i = 0; i < 10; i++)
    {
        printf("%i ",vetor[i]);
    }
    return 0;
}
