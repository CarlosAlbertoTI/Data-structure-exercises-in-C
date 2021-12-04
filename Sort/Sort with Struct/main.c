#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno{
    int matricula;
    char nome[30];
    float n1, n2, n3;
};

struct aluno V[6];


void insertionSortMatricula(struct aluno *V, int N){
    int i,j;    
    struct aluno aux;
    for(i = 1; i < N; i++){
        aux = V[i];
        for(j = i; (j > 0) && (aux.matricula < V[j-1].matricula ); j--){
            V[j] = V[j -1];
        }
        V[j] = aux;
    }
};


void insertionSortNome(struct aluno *V,int N){
    int i,j;    
    struct aluno aux;
    for(i = 1; i < N; i++){
        aux = V[i];
        for(j = i; (j > 0) && (strcmp(aux.nome, V[j-1].nome) < 0); j--){
            V[j] = V[j-1];
        }
        V[j] = aux;
    }
};


int main(){
    int i;

    struct aluno V[4] = {{1,"carlos", 0.0,1.1,2.2},{2,"andre", 1.1,1.5,2.2},{3,"marcos", 2.2,3.5,4.2},{4,"vinicios", 3.3,4.5,5.2}};

    insertionSortNome(V, 4);
    for( i = 0; i < 4;i++)
        printf("%i)  %s\n",i+1, V[i].nome);

    return 1;
};