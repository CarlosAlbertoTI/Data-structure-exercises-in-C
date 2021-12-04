#include <stdio.h>
#include <stdlib.h>
#include "./ListDinEncadDesc.h"

int main(){
    Lista *li;

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


    li = criar_lista();

    int tamanho1 = tamanho_lista(li);
    printf("Tamanho1: %d\n", tamanho1);

    int inserir_inicio =  inserir_lista_inicio(li , al1);
    printf("inserir inicio %i\n", inserir_inicio);

    int inserir_fim = inserir_lista_fim(li , al2);
    printf("inserir fim: %i\n", inserir_fim);

    int imprime1 = imprimir_lista(li);
    printf("imprime1: %i\n", imprime1);

    int remover_inicio = remover_lista_inicio(li);
    printf("remover inicio %i\n", remover_inicio);
    
    int remover_fim = remover_lista_fim(li);
    printf("remover fim %i\n", remover_fim);

    int imprime2 = imprimir_lista(li);
    printf("imprime2: %i\n", imprime2);
    
    libera_lista(li);

    return 1;
}