#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncadDupla.h"

int main(){
    Lista *lista;

    Aluno novoAluno;
    novoAluno.matricula = 123;
    novoAluno.n1 = 3.3;
    novoAluno.n2 = 3.3;
    novoAluno.n3 = 3.3;

    Aluno novoAluno2;
    novoAluno2.matricula = 223;
    novoAluno2.n1 = 3.2;
    novoAluno2.n2 = 3.2;
    novoAluno2.n3 = 3.2;

    Aluno novoAluno3;
    novoAluno3.matricula = 333;
    novoAluno3.n1 = 3.0;
    novoAluno3.n2 = 3.0;
    novoAluno3.n3 = 3.0;

    Aluno novoAluno4;
    Aluno novoAluno5;

    int matriculaAluno = 223;

    lista = criar_lista();
    
    int t_lista = tamanho_lista(lista);
    printf("tamanho da lista: %i\n", t_lista);

    int lista_v = lista_cheia(lista);
    printf("Lista cheia: %i\n",lista_v );

    int lista_vaz = lista_vazia(lista);
    printf("Lista vazia: %i\n", lista_vaz);

    int insere_inicio = inserir_lista_inicio(lista, novoAluno);
    printf("Insere inicio: %i\n", insere_inicio);

    return 1;
    
    int imprime_lista = imprimir_lista(lista);
    printf("imprime lista: %i\n", imprime_lista);

    int insere_fim = inserir_lista_fim(lista, novoAluno3);
    printf("Insere fim: %i\n", insere_fim);

    int imprime_lista2 = imprimir_lista(lista);
    printf("imprime lista: %i\n", imprime_lista2);

    int insere_ordenado = inserir_lista_ordenado(lista, novoAluno2);
    printf("Insere ordenado: %i\n", insere_ordenado);
    
    int imprime_lista3 = imprimir_lista(lista);
    printf("imprime lista: %i\n", imprime_lista3);

    int t_lista2 = tamanho_lista(lista);
    printf("tamanho da lista : %i\n", t_lista2);

    int remover_inicio = remover_lista_inicio(lista);
    printf("Remover inicio: %i\n", remover_inicio);

    int remover_fim = remover_lista_fim(lista);
    printf("Remover fim: %i\n", remover_fim);
    
    int remover_ordenado = remover_lista_ordenado(lista,matriculaAluno);
    printf("Remover ordenado: %i\n", remover_ordenado);
    
    int t_lista3 = tamanho_lista(lista);
    printf("tamanho da lista : %i\n", t_lista3);


    int insere_inicio2 = inserir_lista_inicio(lista, novoAluno);
    printf("Insere inicio: %i\n", insere_inicio2);
    
    int imprime_lista4 = imprimir_lista(lista);
    printf("imprime lista: %i\n", imprime_lista4);

    int consulta_pos = consultar_pos(lista, 1, &novoAluno4);
    printf("Consulta aluno por posicão: %i\n", consulta_pos);
    
    if(consulta_pos == 1) printf("Matricula: %d\n", novoAluno4.matricula);

    int consulta_mat = consultar_mat(lista, 123, &novoAluno5);
    printf("Consulta aluno por matricula: %i\n", consulta_mat);

    if(consulta_mat == 1) printf("Matricula: %d\n", novoAluno5.matricula);
    

    libera_lista(lista);

    return 1;
}