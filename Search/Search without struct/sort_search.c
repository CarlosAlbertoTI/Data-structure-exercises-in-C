#include <stdio.h>
#include <stdlib.h>

int busca_sorteada(int * v, int N, int elemento){
    int i;
    for(i = 0; i < N; i++){
        if(elemento == v[i]){
            return 1;
        }else if(elemento < v[i]){
            return -1;
        }
    }
    return -1;
}

int main(){
    int vet[10] = {-22,-12, -8, -9, 0, 1, 2, 4, 6,  20};
    if(busca_sorteada(vet, 10, 0) != -1){
        printf("OK\n");
    }else{
        printf("Error\n");
    }

    return 1;
}