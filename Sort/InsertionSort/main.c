#include <stdio.h>
#include <stdlib.h>

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

int main(){
    int vet[10] = {-8, 4, 20, -12, 2, 6, -22, -9, 0, 1};

    insertion_sort(vet, 10);

    for(int i = 0; i < 10; i++){
        printf("%i\n", vet[i]);
    }

    return 1;
}