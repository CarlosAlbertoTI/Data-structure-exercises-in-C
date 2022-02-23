#include <stdio.h>
#include <stdlib.h>
#include "Set.h"

int main(){
    Sett* teste = criarSett();
    int valor = 10;
    int valor2 = 5;
    int valor3 = 13;


    inserirSet(teste, valor);
    inserirSet(teste, valor2);
    inserirSet(teste, valor3);

    Sett* teste2 = criarSett();
    int valor1 = 9;
    int valor12 = 5;
    int valor13 = 13;

    inserirSet(teste2, valor1);
    inserirSet(teste2, valor12);
    inserirSet(teste2, valor13);

    
    // int res = inserirSet(teste, 10);
    // if(res == 1){
    //   printf("Valor %i inserido com sucesso!\n", valor);
    // }

    // int res3 = consultaSet(teste, 10);
    // if(res3 == 1){
    //   printf("Valor %i encontrado com sucesso!\n", valor);
    // }else{
    //   printf("Valor %i não existe!\n", 10);
    // }
    
    // int res2 = removerSet(teste, 10);
    // if(res == 1){
    //   printf("Valor %i removido com sucesso!\n", valor);
    // }

    Sett* C = uniaoSet(teste, teste2);
    int x;
    for(beginSet(C);!endSet(C); nextSet(C)){
      getItemSet(C, &x);
      printf("%i \n",x);
    }

    liberaSett(teste);
    liberaSett(teste2);
    liberaSett(C);
    return 0;
}