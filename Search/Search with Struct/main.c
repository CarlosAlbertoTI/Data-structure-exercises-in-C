#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno{
    int matricula;
    char nome[30];
    float n1,n2,n3;
};

struct aluno V[6];

int busca_linear_matricula(struct aluno * v, int N, int elemento){
    int i;
    for(i = 0; i < N; i++){
        if(elemento == v[i].matricula){
            return 1;
        }
    }
    return -1;
}

int busca_linear_nome(struct aluno * v, int N, char* elemento){
    int i;
    for(i = 0; i < N; i++){
        if(strcmp(v[i].nome, elemento) == 0){
            return 1;
        }
    }
    return -1;
}

int main(){
    struct aluno V[4] = {
        {2,"andre", 2.2,3.3,4.4},
        {3,"marcos", 3.2,9.3,4.4},
        {4,"julia", 4.2,3.3,5.4},
        {5,"anderson", 6.2,3.3,10.4}
    };
    
    if(busca_linear_matricula(V, 10, 2) != -1){
        printf("OK\n");
    }else{
        printf("Error\n");
    }
   
    if(busca_linear_nome(V, 10, "marcos") != -1){
        printf("OK\n");
    }else{
        printf("Error\n");
    }

    return 1;
};