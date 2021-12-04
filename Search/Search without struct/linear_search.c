#include <stdio.h>
#include <stdlib.h>

int busca_linear(int * v, int N, int elemento){
    int i;
    for(i = 0; i < N; i++){
        if(elemento == v[i]){
            return 1;
        }
    }
    return -1;
}

int main(){
    int vet[10] = {-8, 4, 20, -12, 2, 6, -22, -9, 0, 1};
    if(busca_linear(vet, 10, 0) != -1){
        printf("OK\n");
    }else{
        printf("Error\n");
    }

    return 1;
}