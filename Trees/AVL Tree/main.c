#include <stdio.h>
#include <stdlib.h>
#include "arvoreAVL.h"

int main()
{
    ArvrAVL *arvAVL;

    arvAVL = cria_arvoreAVL();

    int inserir1 = inserir_arvAVL(arvAVL, 10);
    printf("inserir 1: %i\n", inserir1);


    int del1 = remover_arvAVL(arvAVL, 10);
    printf("remover 1: %i\n", del1);

    int busca1 = consulta_arvAVL(arvAVL, 10);
    printf("busca 1: %i\n", busca1);
    // int height1 = fatorBalanceamento_NO(*arvAVL);
    // printf("height: %i \n", height1);

    // int inserir2 = inserir_arvAVL(arvAVL, 9);
    // printf("inserir 2: %i\n", inserir2);

    // int height2 = fatorBalanceamento_NO(*arvAVL);
    // printf("height: %i \n", height2);

    // int inserir3 = inserir_arvAVL(arvAVL, 23);
    // printf("inserir 3: %i\n", inserir3);

    // int height3 = fatorBalanceamento_NO(*arvAVL);
    // printf("height: %i \n", height3);

    // int inserir4 = inserir_arvAVL(arvAVL, 3);
    // printf("inserir 4: %i\n", inserir4);

    // int height4 = fatorBalanceamento_NO(*arvAVL);
    // printf("height: %i \n", height4);

    // int inserir5 = inserir_arvAVL(arvAVL, 4);
    // printf("inserir 4: %i\n", inserir5);

    // int height5 = fatorBalanceamento_NO(*arvAVL);
    // printf("height: %i \n", height5);

    // int inserir6 = inserir_arvAVL(arvAVL, 17);
    // printf("inserir 5: %i\n", inserir6);

    // int height6 = fatorBalanceamento_NO(*arvAVL);
    // printf("height: %i \n", height6);
    // for (int i = 0; i < 10; i++)
    // {
    //     int validador = inserir_arvAVL(arvAVL, i);
    //     int balanceamento = fatorBalanceamento_NO(*arvAVL);
    //     printf("%i\n", (*arvAVL)->info);
    //     printf("inserir : %i\n", validador);
    //     printf("balanceamento: %i\n",balanceamento);
    // }

    // for (int i = 10; i > 0; i--)
    // {
    //     int validador = remover_arvAVL(arvAVL, i);
    //     int balanceamento = fatorBalanceamento_NO(*arvAVL);
    //     printf("%i\n", (*arvAVL)->info);
    //     printf("remover : %i\n", validador);
    //     printf("balanceamento: %i\n",balanceamento);
    // }

    // preOrdem_ArvoreAVL(arvAVL);

    //  int remove1 = remover_arvAVL(arvAVL, 10);
    //  printf("remover 1: %i\n", remove1);

    libera_ArvAVL(arvAVL);

    return 1;
}
