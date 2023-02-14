#include <stdio.h>
/* 7. Escreva um programa em C para armazenar n elementos em um
array e imprima os elementos usando o ponteiro.

Saída esperada:

Os elementos que você inseriu são:
    elemento -0 : 5
    elemento -1 : 7
    elemento -2 : 2
    elemento -3 : 9
    elemento -4 : 8
*/

int main(void){
    int n, i;

    scanf("%d",&n);

    int v_elementos[n], *p_elementos = &v_elementos;

    for ( i = 0; i < n; i++)
    {
        scanf("%d",&v_elementos[i]);
    }
    
    for ( i = 0; i < n; i++)
    {
        p_elementos[i] = v_elementos[i];

        printf("\nelemento - %d : %d\n", i, p_elementos[i]);
    }
    

    return 0;
}