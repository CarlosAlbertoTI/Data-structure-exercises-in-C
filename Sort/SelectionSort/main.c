#include <stdio.h>
#include <stdlib.h>

void selection_sort(int *v, int N)
{
    int i, j, menor, troca;
    for (i = 0; i < N - 1; i++)
    {
        menor = i;
        for (j = i + 1; j < N; j++)
        {
            if (v[j] < v[menor])
            {
                menor = j;
            }
        }
        if (i != menor)
        {
            troca = v[i];
            v[i] = v[menor];
            v[menor] = troca;
        }
    }
}

int main()
{
    int vet[10] = {-8, 4, 20, -12, 2, 6, -22, -9, 0, 1};

    selection_sort(vet, 10);

    for (int i = 0; i < 10; i++)
    {
        printf("%i\n", vet[i]);
    }

    return 1;
}