#include <stdio.h>
#include <stdlib.h>
#include "./ListDinEncCir.h"

int main(){
    Lista *lista;

    lista = criar_lista();

    Aluno al1;
    al1.matricula = 111;
    al1.n1 = 11.0;
    al1.n2 = 11.1;
    al1.n3 = 11.1;

    Aluno al2;
    al2.matricula = 222;
    al2.n1 = 22.0;
    al2.n2 = 22.1;
    al2.n3 = 22.2;

    Aluno al3;
    al3.matricula = 333;
    al3.n1 = 33.0;
    al3.n2 = 33.2;
    al3.n3 = 33.3;
    
    Aluno al4;
    Aluno al5;

    int tamanho1 = tamanho_lista(lista);
    printf("Tamanho1: %i\n", tamanho1);

    int lista_vazia1 = lista_vazia(lista);
    printf("lista vazia: %i\n", lista_vazia1);

    printf("%p\n", lista);
    
    int insere_inicio = inserir_lista_inicio(lista, al1);
    printf("insere inicio: %i\n", insere_inicio);

    return 1;

    int insere_fim = inserir_lista_fim(lista, al3);
    printf("insere final: %i\n", insere_fim);
   
    int insere_ordenado = inserir_lista_ordenado(lista, al2);
    printf("insere ordenado: %i\n", insere_ordenado);

    int imprime1 = imprimir_lista(lista);
    printf("imprime 1: %i\n",imprime1);

    int busca_pos = consultar_pos(lista, 2, &al4);
    if(busca_pos == 1){
        printf("matricula pos: %d\n", al4.matricula);
    }

    int busca_mat = consultar_mat(lista, 111, &al5);
    if(busca_mat == 1){
        printf("matricula mat: %d\n", al5.matricula);
    }
    
    int remover_inicio =  remover_lista_inicio(lista);
    printf("remover inicio: %i\n", remover_inicio);

    int remover_fim = remover_lista_fim(lista);
    printf("remover fim: %i\n", remover_fim);
    
    int remover_ordenado = remover_lista_ordenado(lista, 222);
    printf("remover ordenado: %i\n", remover_ordenado);
    
    int imprime2 = imprimir_lista(lista);
    printf("imprime 2: %i\n",imprime2);


    libera_lista(lista);

    return 1;
}