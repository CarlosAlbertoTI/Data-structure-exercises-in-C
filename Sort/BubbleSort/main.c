#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int * v, int N){
    int i, continua, aux, fim = N;
    do{
        for(i = 0; i < fim -1 ; i++){
            if(v[i] > v[i+1]){
                aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
                continua = i;
            }
        }
        fim--;
    }while(continua != 0);
}

int main(){
    int vet[10] = {-8, 4, 20, -12, 2, 6, -22, -9, 0, 1};

    bubbleSort(vet, 10);

    for(int i = 0; i < 10; i++){
        printf("%i\n", vet[i]);
    }

    return 1;
}