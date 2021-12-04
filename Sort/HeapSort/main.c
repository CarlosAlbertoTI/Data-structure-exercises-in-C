#include <stdio.h>
#include <stdlib.h>

void criarHeap(int * vetor, int inicio, int fim){
    int pai = vetor[inicio];
    int filho = inicio *2 +1;
    while(filho <= fim){
        if(filho < fim){
            if(vetor[filho] < vetor[filho+1]){
                filho+=1;
            }
        }
        if(pai < vetor[filho]){
            vetor[inicio] = vetor[filho];
            inicio = filho;
            filho = 2 * inicio +1; 
        }else{
            filho = fim +1;
        }
    }
    vetor[inicio] = pai;
}

void heapSort(int * vetor, int N){
    int i, aux;
    for( i = (N-1)/2; i >= 0; i--){
        criarHeap(vetor, i, N-1);
    }
    for(i = N-1; i >= 1; i--){
        aux = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = aux;
        criarHeap(vetor, 0, i - 1);
    }
}

int main(){

    int vetor[9] = {3,6,12,8,34,8,23,14,7};
    heapSort(vetor,10);
    for(int i = 0; i < 9; i++){
        printf("%i\n", vetor[i]);
    }

    return 0;
}