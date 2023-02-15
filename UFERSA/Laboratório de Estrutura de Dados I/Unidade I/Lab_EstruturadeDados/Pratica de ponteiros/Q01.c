#include <stdio.h>

/*
1. Quais serão os valores de x, y e p ao final do trecho de código abaixo:
*/

int main(void){
    
    int x, y, *p;
    
    y = 0;
    //y = 0: aqui atribuimos 0 a y.
    
    p = &y;
    //p está apontando para o endereço de y, ou seja, o conteúdo de p = 0.

    x = *p;
    //x está recebendo o valor de p, x = 0.

    x = 4;
    //foi atribuido o valor 4 para x, mas, não se altera o valor do ponteiro, e nem tanto a variável apontada por p.

    (*p)++;
    //está sendo incrementado o valor de p, ou seja, p = 1, e y = 1. 
    
    --x;
    //x = 3, pois x foi decrementado.

    (*p) += x;
    //aqui estamos somando o conteúdo de p = 1 (consequentemente estaremos modificando o valor de y) com x = 3. Portanto p = 4, y = 4.
    
    //agora exibiremos os valores das variáveis.
    printf("Valor de x: %d\nValor de y: %d\nValor de p %d\n", x, y, *p);

    return 0;
}