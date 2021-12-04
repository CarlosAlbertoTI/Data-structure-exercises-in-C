#include <stdio.h>
#include <stdlib.h>

int busca_binaria(int * v, int N, int elemento){
    int i, inicio, meio, final;
    inicio = 0;
    final = N - 1;
    while(inicio <= final){
        meio = (final + inicio)/2;
        if(v[meio] > elemento){
            inicio = meio + 1;
        }else if(v[meio] < elemento){
            final = meio -1;
        }else{
            return meio;
        }
    }
    return -1;
}

int main(){

    int vet[10] = {-22,-12, -8, -9, 0, 1, 2, 4, 6,  20};
    if(busca_binaria(vet, 10, 0) != -1){
        printf("OK\n");
    }else{
        printf("Error\n");
    }
    return 1;
}