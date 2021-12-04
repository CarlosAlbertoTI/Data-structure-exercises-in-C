#include <stdio.h>
#include <stdlib.h>

struct aluno {
    int matricula;
    char nome[30];
    float n1, n2, n3;
};

typedef struct aluno Aluno;

typedef struct descritor Lista;

Lista* criar_lista();
void libera_lista(Lista *lista);
int tamanho_lista(Lista *lista);

int inserir_lista_inicio(Lista* lista, struct aluno novoAluno);
int inserir_lista_fim(Lista* lista,struct aluno novoAluno);

int remover_lista_inicio(Lista* lista);
int remover_lista_fim(Lista* lista);

int imprimir_lista(Lista* lista);