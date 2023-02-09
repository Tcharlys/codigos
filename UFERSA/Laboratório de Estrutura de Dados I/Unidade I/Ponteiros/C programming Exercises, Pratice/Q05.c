#include <stdio.h>
/* 5. Escreva um programa em C para somar numeros usando chamada
por referencia.

Saída esperada:
A soma de 5 e 6 é 11
*/

int calculoSoma(int *n1, int *n2){
    int resultado = *n1 + *n2;

    return resultado;
}
int main(){
    int n1, n2, soma;

    printf("Insira o primeiro numero.\n");
    scanf("%d", &n1);

    printf("Insira o segundo numero.\n");
    scanf("%d", &n2);

    soma = calculoSoma(&n1, &n2);
    
    printf("A soma de %d e %d eh %d\n", n1, n2, soma);

    return 0;
}