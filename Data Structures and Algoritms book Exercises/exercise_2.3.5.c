#include <stdio.h>
#include <stdlib.h>

void binarySearch(int inicio, int fim, int *lista, int valorB);
int arr[] = {101,50,60,30,10};
void solve(int idx, int sum){
    if(idx >= 11){
        return;
    }
    if(sum-arr[idx] == 0){
        printf("achei!");
        return;
    }
    solve(idx+1,sum-arr[idx]);
    solve(idx+1,sum);
}

int main(){
    int listaSort[] = {2,4,5,10,12,16,23,30,55,60};
    int tamanho = 4;
    int valor = 23;
    // binarySearch(0,10, listaSort, valor);
    solve(0,100);
    return 0;
}

void binarySearch(int inicio, int fim, int *lista, int valorB){
    while(inicio <= fim){
       int médio = (inicio+fim)/2; 
       //inicio + range/2  
    //    0+(fim/2)
    //       
       if(lista[médio] == valorB){
           printf("achou!!!!");
           return;
       }else{

           if(lista[médio] > valorB){
                fim = médio -1;             
           }else{
               inicio = médio +1;
           }
       }
    }
    printf("Nao achou!");
   
   
   
    if(fim >= 0){
        int meio = inicio+(fim-inicio)/ 2;
        
        if((lista)[meio] == valorB){
            printf("Valor encontrado!\n");
            printf("%d - %d",(lista)[meio], valorB);
            return;
        }

        if((lista)[meio] > valorB){
        
        // printf("valor : %i\n", lista[fim/2]);
            return binarySearch(inicio, meio-1, lista, valorB);
        
        }else if((lista)[meio] < valorB){
        
            return binarySearch(meio+1, fim, lista, valorB);
        
        }
    }
}