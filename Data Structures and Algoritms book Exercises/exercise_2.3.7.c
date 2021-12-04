#include <stdio.h>
#include <stdlib.h>

int arr[] = {2,4,6,4,7,10,23};
int arr2[] = {2,4,6,4,7,10,23};

void encontrarSoma(int valorDesejado, int tamanhoArray){
    for(int i = 0; i < tamanhoArray; i++  ){
        for(int j = 0; j < tamanhoArray; j++){
            if(arr[i]+arr[j] == valorDesejado){
                printf("Achei!!");
                return;
            }
        }
    }
}



int main(){
    int n = 43;
    encontrarSoma(n,7);
}