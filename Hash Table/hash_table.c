#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_table.h"

struct hash{
    int quantidade, TABLE_SIZE;
    struct aluno **dados;
};

Hash* criarHash(int TABLE_SIZE){   
    Hash* hash = (Hash*) malloc(sizeof(Hash));
    if(hash != NULL){
        int i;
        hash->TABLE_SIZE = TABLE_SIZE;
        hash->dados = (struct aluno **) malloc(TABLE_SIZE * sizeof(struct aluno*));
        if(hash->dados == NULL){
            free(hash);
            return NULL;
        }

        hash->quantidade = 0;
        for ( i = 0; i < TABLE_SIZE; i++){
            hash->dados[i] = NULL;
        }

    }
        return hash;
}

void liberaHash(Hash * hash){
    if(hash != NULL){
        int i;
        for(i= 0; i< hash->TABLE_SIZE; i++){
            if(hash->dados[i] != NULL){
                free(hash->dados[i]);
            }
        }
        free(hash->dados);
        free(hash);
    }
}

int valorString(char *str){
    int i, valor = 7;
    int tam = strlen(str);
    for(i=0; i < tam; i++)
        valor = 31 * valor + (int) str[i];
    return (valor & 0x7FFFFFFF);
}

//Hash Divisao
//int chave = valorString(nome);
//pos = chaveDivisao(chave, TABLE_SIZE)
int chaveDivisao(int chave, int TABLE_SIZE){
    return (chave & 0x7FFFFFFF) % TABLE_SIZE;
}

int insere_hash_sem_colisao(Hash * hash, struct aluno al){
    if(hash == NULL || hash->quantidade == hash->TABLE_SIZE)
        return 0;
    int chave = al.matricula;

    int pos = chaveDivisao(chave,hash->TABLE_SIZE);
    struct aluno *novo;
    novo = (struct aluno*)malloc(sizeof(struct aluno));
    if(novo == NULL)
        return 0;
    
    *novo = al;
    hash->dados[pos] = novo;
    hash->quantidade++;
    return 1;
}

int busca_hash_sem_colisao(Hash * hash, int matricula, struct aluno *al){
    if(hash == NULL)
        return 0;
    
    int pos = chaveDivisao(matricula, hash->TABLE_SIZE);
    if(hash->dados[pos] == NULL)
        return 0;

    *al = *(hash->dados[pos]);
    return 1;
    
}

int sondagemLinear(int pos, int i, int TABLE_SIZE){
    return ((pos + i) & 0x7FFFFFFF) % TABLE_SIZE;
}

int insere_hash_ender_aberto(Hash * hash, struct aluno al){
    if(hash == NULL || hash->quantidade == hash->TABLE_SIZE)
        return 0;

    int chave = al.matricula;
    int i, pos, newPos;
    pos = chaveDivisao(chave, hash->TABLE_SIZE);
    for(i = 0; i < hash->TABLE_SIZE; i++){
        newPos = sondagemLinear(pos, i, hash->TABLE_SIZE);
        if(hash->dados[newPos] == NULL){
            struct aluno* novo;
            novo = (struct aluno*) malloc( sizeof(struct aluno));
            if(novo == NULL)
                return 0;
            
            *novo = al;
            hash->dados[newPos] = novo;
            hash->quantidade++;
            return 1;
        }
    }
    return 0;
}

int busca_hash_ender_aberto(Hash * hash, int matricula, struct aluno *al){
    if(hash == NULL)
        return 0;
    
    int i, pos, newPos;
    pos = chaveDivisao(matricula, hash->TABLE_SIZE);
    for(i = 0; i < hash->TABLE_SIZE; i++){
        newPos = sondagemLinear(pos, i , hash->TABLE_SIZE);
        if(hash->dados[newPos] == NULL)
            return 0;
        if(hash->dados[newPos]->matricula == matricula){
            (*al) = *(hash->dados[newPos]);
            return 1;
        }
    }
    return 0;
}