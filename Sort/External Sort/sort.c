#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"

#define N 100

void criaArquivoTeste(char * nome){

    int i;
    FILE *f = fopen(nome, "w");
    srand(time(NULL));
    
    for ( i = 0; i < 1000; i++){
        fprintf(f, "%d\n",rand());
    }
    fprintf(f,"%d", rand());
    fclose(f);
   
}

int compara(const void *a, const void *b){
    if(*(int*)a == *(int*)b)
        return 0;//iguais
    else
        if(*(int*)a < *(int*)b)
            return -1; //vem antes
        else
            return 1; //vem depois
}

void salvarArquivo(char * nome, int * V, int tam, int mudaLinhaFinal){
    int i;
    FILE *f = fopen(nome, "a");
    for(i = 0; i < tam - 1; i++){
        fprintf(f,"%d\n",V[i]);
    }

    if(mudaLinhaFinal == 0)
        fprintf(f, "%d", V[tam-1]);
    else
        fprintf(f, "%d\n", V[tam-1]);

    fclose(f);
}

int criaArquivosOrdenados(char * nome){
    int V[N], cont = 0, total = 0;
    char novo[20];
    FILE *f = fopen(nome, "r");

    while(!feof(f)){
        fscanf(f,"%d", &V[total]);
        total++;
        if(total == N){
            cont++;
            sprintf(novo,"Temp%d.txt", cont);
            qsort(V, total, sizeof(int), compara);
            salvarArquivo(novo, V, total, 0);
            total = 0;
        }
    }
    if(total > 0){
        cont++;
        sprintf(novo, "Temp%d.txt",cont);
        qsort(V,total,sizeof(int), compara);
        salvarArquivo(novo, V, total, 0);
    }
    fclose(f);
    return cont;
}

int procuraMenor(struct arquivo* arq, int numArgs, int K, int * menor){
    int i, idx = -1;
    
    for(i = 0; i < numArgs; i++){
        if(arq[i].pos < arq[i].MAX){
            if(idx == -1){
                idx = i;
            }else{

                if(arq[i].buffer[arq[i].pos] < arq[idx].buffer[arq[idx].pos]){
                    idx = 1;
                }
            }
        }

    }

    if(idx != -1){
        *menor = arq[idx].buffer[arq[idx].pos];
        arq[idx].pos++;
        if(arq[idx].pos == arq[idx].MAX)
            preencheBuffer(&arq[idx], K);
        return 1;

    }else{
        return 0;
    }

}

void preencheBuffer(struct arquivo* arg, int K){
    int i;
    if(arg->f == NULL){
        return;
    }

    arg->MAX = 0;
    arg->pos = 0;
    for(i = 0; i < K; i++){
        if(!feof(arg->f)){
            fscanf(arg->f,"%d",&arg->buffer[arg->MAX]);
            arg->MAX++;
        }else{
            fclose(arg->f);
            arg->f = NULL;
            break;
        }
    }
}

void merge(char * nome, int numArqs, int K ){
    char novo[20];
    int i;
    int *buffer = (int*) malloc(K * sizeof(int));

    struct arquivo* arq;
    arq = (struct arquivo*) malloc(numArqs * sizeof(struct arquivo));

    for(i = 0; i < numArqs; i++){
        sprintf(novo, "Temp%d.txt", i+1);
        arq[i].f = fopen(nome,"r");
        arq[i].MAX = 0;
        arq[i].pos = 0;
        arq[i].buffer = (int*) malloc(K * sizeof(int));
        preencheBuffer(&arq[i], K); 
    }

    int menor, quantidadeBuffer = 0;
    while(procuraMenor(arq, numArqs, K, &menor) == 1){
        buffer[quantidadeBuffer] = menor;
        quantidadeBuffer++;
        if(quantidadeBuffer == K){
            salvarArquivo(nome, buffer, K, 1);
            quantidadeBuffer = 0;
        }
    }    

    if(quantidadeBuffer != 0)
        salvarArquivo(nome, buffer, quantidadeBuffer, 1);

   for(i = 0; i< numArqs; i++)
       free(arq[i].buffer);
   
   free(arq);
   free(buffer);
}

void mergeSortExterno(char * nome){
    char novo[20];
    int numArgs = criaArquivosOrdenados(nome);
    int i, K = N / (numArgs + 1);

    remove(nome);
    merge(nome, numArgs, K);

    for(i = 0; i < numArgs; i++){
        sprintf(novo, "Temp%d.txt", i+1);
        remove(novo);
    }
}