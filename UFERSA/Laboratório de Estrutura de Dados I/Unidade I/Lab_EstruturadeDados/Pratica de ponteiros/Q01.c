#include <stdio.h>

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
    //
    --x;
    (*p) += x;
    
    return 0;
}