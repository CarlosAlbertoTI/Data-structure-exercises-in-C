#include <stdio.h>
#include <stdlib.h>
#include "Ponto.h"

int main(){
    float d;
    Ponto *p, *q;

    p = pto_cria(10,22);
    q = pto_cria(5, 5);

    d = pto_distancia(p,q);
    printf("A distancia entre pontos: %f", d);
    
    pto_libera(p);
    pto_libera(q);

    system('pause');
    return 0;
}