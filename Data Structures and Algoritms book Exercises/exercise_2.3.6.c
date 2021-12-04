#include <stdio.h>
#include <stdlib.h>

int arr[] = {1, 3, 6, 8, 10}; 
int binary_search(int inicio, int fim, int numeroDesejado){
    int numb = -1;
    while(inicio <= fim){
        int meio = (fim+inicio)/2;
        if(arr[meio] > numeroDesejado){
            numb = meio;
            fim = meio -1;

        }else{
            inicio = meio +1;    
        }  
    }
    return numb;
}

void insertionSort(int arr[], int n){ 
    int i, key, j; 
    for (i = 1; i < n; i++)
    { 
        key = arr[i]; 
        j = i - 1; 
 
        /* Move elements of arr[0..i-1], that are 
        greater than key, to one position ahead 
        of their current position */
        int i = binary_search(0,i,key);
        // if(){

        // }
        arr[j + 1] = key; 
    } 
}
// 1 100
// 100 1
int main(){ 
    int n = sizeof(arr) / sizeof(arr[0]); 
 
    // insertionSort(arr, n); 
    int i = binary_search(0,5,11);
    if(i != -1)printf("%i", arr[i]);
    else printf("%i", i);
    return 0; 
} 