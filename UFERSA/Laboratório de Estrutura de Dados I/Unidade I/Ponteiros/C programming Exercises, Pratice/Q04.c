#include <stdio.h>

/* 4. Escreva um programa em C para somar dois números usando
ponteiros.

Saída esperada:
A soma dos números inseridos é 11
*/

int main(){
    float n1, n2, *p_n1 = &n1, *p_n2 = &n2;

    scanf("%f %f", &n1, &n2);
    
    printf("A soma dos numeros inseridos e: %f\n", (*p_n1 + *p_n2));

    return 0;
}