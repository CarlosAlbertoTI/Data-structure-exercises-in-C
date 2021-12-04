#include <stdio.h>
#include <stdlib.h>
#include "./DynaQueue.h"

int main(){
    Fila *fi;
    fi = criar_fila();

    Aluno al2;

    Aluno al1;
    al1.matricula = 123;
    al1.n1 = 1.1;
    al1.n2 = 2.1;
    al1.n3 = 3.1;

    int tamanho1 = tamanho_fila(fi);
    printf("tamanho1: %i\n", tamanho1);

    int inserir1 = insere_fila(fi,al1);
    printf("inserir1: %i\n", inserir1);

    int inserir2 = insere_fila(fi,al1);
    printf("inserir2: %i\n", inserir2);

    int imprimir1 = imprime_lista(fi);
    printf("imprimir1: %i\n", imprimir1);

    int remove1 = remove_fila(fi);
    printf("remove1: %i\n", remove1);

    int consulta1 = consulta_fila(fi, &al2);
    printf("consulta1: %i\n", consulta1);

    printf("matricula: %i\n", al2.matricula);

    int remove2 = remove_fila(fi);
    printf("remove1: %i\n", remove2);


    int imprimir2 = imprime_lista(fi);
    printf("imprimir2: %i\n", imprimir2);

    int fila_vazia1 = fila_vazia(fi);
    printf("fila vazia: %i\n", fila_vazia1);

    liberar_fila(fi);
    return 0;
}