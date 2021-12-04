#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListDinEnc.h"

int main(){
    Lista *li = criar_lista();

    Aluno dadoAluno;
    Aluno dadoAluno2;
    Aluno dadoAluno3;
    Aluno dadoAluno4;
    Aluno dadoAluno5;
    
    dadoAluno.matricula = 123;
    strcpy(dadoAluno.nome,"Carlos");
    dadoAluno.n1 = 4.4;
    dadoAluno.n2 = 7.4;
    dadoAluno.n3 = 9.4;
    
    dadoAluno2.matricula = 456;
    strcpy(dadoAluno2.nome,"Andre");
    dadoAluno2.n1 = 4.4;
    dadoAluno2.n2 = 6.4;
    dadoAluno2.n3 = 10.0;

    dadoAluno3.matricula = 789;
    strcpy(dadoAluno3.nome,"Felipe");
    dadoAluno3.n1 = 1.3;
    dadoAluno3.n2 = 6.0;
    dadoAluno3.n3 = 9.4;

    int matricula_aluno = 456;
    int posicao = 1;
    
    int tamanho = tamanho_lista(li);
    printf("tamanho : %i\n",tamanho);
    
    int listaCheia = lista_cheia(li);
    printf("lista_cheia : %i\n",lista_cheia(li));
    int listaVazia = lista_vazia(li);
    printf("lista_vazia : %d\n",listaVazia);

    int inserirListaInicio = insere_lista_inicio(li, dadoAluno);
    printf("inserirListaInicio : %i\n",inserirListaInicio);
    
    int imprimir_lista1 = imprimir_lista(li);
    printf("imprimir lista: %i\n", imprimir_lista1);

    int inserirListaFinal = insere_lista_final(li, dadoAluno2);
    printf("inserirListaFinal : %i\n",inserirListaFinal);

    int imprimir_lista2 = imprimir_lista(li);
    printf("imprimir lista: %i\n", imprimir_lista2);

    int tamanho2 = tamanho_lista(li);
    printf("tamanho : %i\n",tamanho2);

    int inserirListaOrdenada = insere_lista_ordenada(li,dadoAluno3);
    printf("inserirListaOrdenada : %i\n",inserirListaOrdenada);

    int imprimir_lista3 = imprimir_lista(li);
    printf("imprimir lista: %i\n", imprimir_lista3);

    int tamanho3 = tamanho_lista(li);
    printf("tamanho : %i\n",tamanho3);

    int removeListaInicio = remove_lista_inicio(li);
    printf("removeListaInicio : %i\n",removeListaInicio);

    int imprimir_lista4 = imprimir_lista(li);
    printf("imprimir lista: %i\n", imprimir_lista4);

    int removeListaFinal = remove_lista_final(li);
    printf("removeListaFinal : %i\n",removeListaFinal);

    int imprimir_lista5 = imprimir_lista(li);
    printf("imprimir lista: %i\n", imprimir_lista5);

    int removerLista = remove_lista(li, matricula_aluno);
    printf("removerLista : %i\n",removerLista);

    int imprimir_lista6 = imprimir_lista(li);
    printf("imprimir lista: %i\n", imprimir_lista6);

    int inserirListaFinal2 = insere_lista_final(li, dadoAluno2);
    printf("inserirListaFinal : %i\n",inserirListaFinal2);

    int imprimir_lista7 = imprimir_lista(li);
    printf("imprimir lista: %i\n", imprimir_lista7);

    int consultaListaPos = consulta_lista_pos(li, posicao, &dadoAluno4);
    printf("consultaListaPos : %i\n",consultaListaPos);
    
    if(consultaListaPos == 1) printf("Matricula: %d\n", dadoAluno4.matricula);

    int consultaListMat = consulta_lista_mat(li,matricula_aluno, &dadoAluno5);
    printf("consultaListMat : %i\n",consultaListMat);

    if(consultaListMat == 1) printf("Matricula: %d\n", dadoAluno5.matricula);

    libera_lista(li);

    return 1;
}