#include <stdio.h>

/*
11. Escreva um programa em C para trocar elementos usando
chamada por referência.

Dados de teste:

Insira o valor do 1º elemento: 5
Insira o valor do 2º elemento: 6
Insira o valor do 3º elemento: 7

Saída esperada:

Os valores antes da troca são:
elemento 1 = 5
elemteno 2 = 6
elemento 3 = 7

Os valores após a troca são:
elemento 1 = 7
elemento 2 = 5
elemento 3 = 6
*/

void embaralha_num(int *x, int *y, int *z){
    int tmp;
    tmp = *y;
    *y = *x;
    *x = *z;
    *z = tmp;
}

int main(){
    int num1, num2, num3;

    printf("Digite o valor do primeiro elemento\n");
    scanf("%d", &num1);

    printf("Digite o valor do segundo elemento\n");
    scanf("%d", &num2);

    printf("Digite o valor do terceiro elemento\n");
    scanf("%d", &num3);

    printf("\nelemento 1 = %d\n", num1);
    printf("elemento 2 = %d\n", num2);
    printf("elemento 3 = %d\n", num3);
    
    embaralha_num(&num1, &num2, &num3);

    printf("\nelemento 1 = %d\n", num1);
    printf("elemento 2 = %d\n", num2);
    printf("elemento 3 = %d\n", num3);
    
    return 0;
}