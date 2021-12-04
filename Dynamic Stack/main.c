#include <stdio.h>
#include <stdlib.h>
#include "./DynamicStack.h"

int main(){
    Pilha* pi;

    Aluno al3;

    Aluno al1;
    al1.matricula = 123;
    al1.n1 = 1.1;
    al1.n2 = 2.1;
    al1.n3 = 3.1;

    Aluno al2;
    al2.matricula = 222;
    al2.n1 = 22.0;
    al2.n2 = 22.1;
    al2.n3 = 22.2;

    pi = criar_pilha();

    int vazia1 = pilha_vazia(pi);
    printf("lista vazia: %i\n",vazia1);

    int inserir1 = inserir_pilha(pi, al1);
    printf("inserir1: %i", inserir1);

    int inserir2 = inserir_pilha(pi, al2);
    printf("inserir2: %i", inserir2);

    int tamanho1 = tamanho_pilha(pi);
    printf("tamanho1: %i\n",tamanho1);

    int consulta1 = consulta_pilha(pi, &al3);
    if(consulta1 == 1){
        printf("matricula: %i\n", al3.matricula);
    }

    int imprime1 = imprime_pilha(pi);
    printf("imprim1: %i\n", imprime1);


    int delete1 = remove_pilha(pi);
    int delete2 = remove_pilha(pi);

    int imprime2 = imprime_pilha(pi);
    printf("imprim1: %i\n", imprime2);

    liberar_pilha(pi);

    return 1;
}