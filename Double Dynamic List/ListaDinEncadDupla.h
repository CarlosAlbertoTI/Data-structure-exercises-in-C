#include <stdio.h>
#include <stdlib.h>

struct aluno{
    int matricula;
    char nome[30];
    float n1,n2,n3;
};

typedef struct aluno Aluno;
// addr -> valor
// addr -> (addr2) -> valor
// addr -> (addr3) -> valor
// int *data
// data = tar; 
// *data = 30; 

typedef struct elemento* Lista;

Lista* criar_lista();
void libera_lista(Lista* lista);
int tamanho_lista(Lista* lista);
int lista_cheia(Lista* lista);
int lista_vazia(Lista* lista);
int inserir_lista_inicio(Lista* lista, struct aluno novoAluno);
int inserir_lista_fim(Lista* lista,struct aluno novoAluno);
int inserir_lista_ordenado(Lista* lista,struct aluno novoAluno);
int remover_lista_inicio(Lista* lista);
int remover_lista_fim(Lista* lista);
int remover_lista_ordenado(Lista* lista,int mat);
int consultar_pos(Lista* lista, int pos, struct aluno *al);
int consultar_mat(Lista* lista, int mat, struct aluno *al);
int imprimir_lista(Lista* lista);
