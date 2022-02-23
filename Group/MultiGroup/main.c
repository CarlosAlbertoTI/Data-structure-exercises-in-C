#include <stdio.h>
#include "Bag.h"

int main(void) {

  Bag* teste = criarBag();
    int valor = 10;
    int valor2 = 5;
    int valor3 = 13;
    int valor4 = 5;

    insereBag(teste, valor);
    insereBag(teste, valor2);
    insereBag(teste, valor3);

    removerBag(teste, 5);

    Bag* teste2 = criarBag();
    int valor1 = 9;
    int valor12 = 5;
    int valor13 = 13;

    insereBag(teste2, valor1);
    insereBag(teste2, valor12);
    insereBag(teste2, valor13);

    int x;
    for(beginBag(teste);!endBag(teste); nextBag(teste)){
      getItemBag(teste, &x);
      printf("%i \n",x);
    }

    liberaBag(teste);
    liberaBag(teste2);


  printf("Hello World\n");
  return 0;
}