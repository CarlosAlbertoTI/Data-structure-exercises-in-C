#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int particiona(int * v, int inicio, int fim){
    int esq, dir, pivô, aux;

    esq = inicio;
    dir = fim;
    pivô = v[inicio];

    while(esq < dir){
        while(v[esq] <= pivô){
            esq++;
        }
        while(v[dir] > pivô){
            dir--;
        }
        if(esq < dir){
            aux = v[esq];
            v[esq] = v[dir];
            v[dir] = aux;
        }
    }
    v[inicio] = v[dir];
    v[dir] = pivô;
    return dir;
}

void quick_sort(int *v, int inicio, int fim)
{
   int pivô;
   if(inicio < fim){
       pivô = particiona(v, inicio, fim);
       quick_sort(v, inicio, pivô-1);
       quick_sort(v, pivô+1, fim);
   }
}

int main()
{
    int vet[10] = {-8, 4, 20, -12, 2, 6, -22, -9, 0, 1};

    quick_sort(vet, 0, 10);

    for (int i = 0; i < 10; i++)
    {
        printf("%i\n", vet[i]);
    }

    return 1;
}