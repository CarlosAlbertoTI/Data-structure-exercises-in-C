#include <stdio.h>
#include <stdlib.h>
#include "./StaticQueue.h"

int main(){
    Fila *fi;
    fi = criar_fila();

    Aluno al2;


    Aluno al1;
    al1.matricula = 123;
    al1.n1 = 1.1;
    al1.n2 = 2.1;
    al1.n3 = 3.1;

    int insere_fila1 = insere_fila(fi, al1);
    printf("inserir fila1: %i\n", insere_fila1);

    int insere_fila2 = insere_fila(fi, al1);
    printf("inserir fila2: %i\n", insere_fila2);
    
    int tamanho1 = tamanho_fila(fi);
    printf("tamanho1: %i\n", tamanho1);
    
    int fila_cheia1 = fila_cheia(fi);
    printf("fila cheia1: %i\n", fila_cheia1);
    
    int imprime1 = imprime_lista(fi);
    printf("imprime1: %i\n", imprime1);

    int remove1 = remove_fila(fi);
    printf("remove fila1: %i\n", remove1);

    int consulta1 = consulta_fila(fi, &al2);
    printf("consulta1: %i\n", consulta1);

    printf("matricula: %d\n",al2.matricula);

    int remove2 = remove_fila(fi);
    printf("remove fila2: %i\n", remove2);

    int imprime2 = imprime_lista(fi);
    printf("imprim2: %i\n", imprime2);
    
    int fila_vazia1 = fila_vazia(fi);
    printf("fila vazia1: %i\n", fila_vazia1);

    libera_fila(fi);
    return 0;
}