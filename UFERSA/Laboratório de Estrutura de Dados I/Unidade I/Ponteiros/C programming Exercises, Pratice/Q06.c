#include <stdio.h>

/* 6. Escreva um programa em C par encontrar o numero maximo entre
dois numeros usando um ponteiro.

Saída esperada:

6 eh o numero maximo.
*/

int main(){

    int n1, n2, *p_n1 = &n1, *p_n2 = &n2;

    printf("Insira o primeiro numero.\n");
    scanf("%d", &n1);

    printf("Insira o segundo numero.\n");
    scanf("%d", &n2);

    if (*p_n2 > *p_n1){
        printf("\n%d eh o numero maximo.\n", *p_n2);
    }
    else
    {
        printf("\n%d eh o numero maximo.\n", *p_n1);
    }
      
    return 0;
}