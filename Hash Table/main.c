#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_table.h"


int main(){
    Hash* hash;
    hash = criarHash(1427);

    Aluno a1;
    a1.matricula = 123;
    char nome[30] = "Carlos Alberto";
    strcpy((a1).nome, nome);
    a1.n1 = 10.0;
    a1.n2 = 0.5;

    Aluno a2;
    a2.matricula = 222;
    char nome2[30] = "Andre Alberto";
    strcpy((a2).nome, nome2);
    a2.n1 = 9.0;
    a2.n2 = 7.5;

    Aluno teste;
    Aluno teste2;

    int inserirAluno1 = insere_hash_sem_colisao(hash, a1);
    if(inserirAluno1 == 0){
        printf("Error ao inserir aluno\n");
    }

    int buscarAluno1 = busca_hash_sem_colisao(hash, a1.matricula,&teste);
    if(buscarAluno1 == 0){
        printf("Error ao buscar aluno\n");
    }

    int inserirAluno2SCol = insere_hash_ender_aberto(hash,a2);
    if(inserirAluno2SCol == 0){
        printf("Error ao inserir aluno2 \n");
    }

    int buscarAluno2SCol = busca_hash_sem_colisao(hash, a2.matricula, &teste2);
    if(buscarAluno2SCol == 0){
        printf("Error ao buscar aluno2 \n");
    }

    printf("Matricula aluno : %i\n", teste.matricula);
    printf("Nome aluno : %s\n", teste.nome);

    printf("Matricula aluno2: %i\n", teste2.matricula);
    printf("Nome aluno2 : %s\n", teste2.nome);


    liberaHash(hash);
    return 1;
}