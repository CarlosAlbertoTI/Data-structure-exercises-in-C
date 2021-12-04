#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaSequencia.h"


int main() {
    Aluno dadosAluno;

    int matriculaAluno = 123;
    int posicao = 3;

    dadosAluno.matricula = 123;
    strcpy(dadosAluno.nome,"Carlos");
    dadosAluno.n1 = 7.8;
    dadosAluno.n2 = 6.6;
    dadosAluno.n3 = 10.0;

    Lista *li;

    li = criarLista();
    int x = tamanhoLista(li);
    int y = listaCheia(li);
    int z = insereListaFinal(li, dadosAluno);
    int q = insereListaInicio(li, dadosAluno);
    int w = insereListaOrdenada(li, dadosAluno);
    int s = removerListaFinal(li);
    int t = removerListaInicio(li);
    int v = removerLista(li, matriculaAluno);
    int d = consultaListaPos(li, posicao, dadosAluno);
    int r = consultaListaMat(li, matriculaAluno, dadosAluno);

    liberaLista(li);

    return 0;
}
