#include <stdio.h>
/*
12. Escreva um programa em C para encontrar o fatorial de um
determinado número usando ponteiros.

Dados de teste;
Insira um número: 5

Saída esperada:
O fatorial de 5 é: 120
*/
void fatorial(int num, int *fatorial){
    int i;
    *fatorial = 1;

    for ( i = 1; i <= num; i++)
    {
        *fatorial *= i;
    }
}

int main(){
    int num, p;

    printf("Digite um numero qualquer\n");
    scanf("%d",&num);

    fatorial(num, &p);

    printf("\nO fatorial de %d eh: %d\n", num, p);

    return 0;
}