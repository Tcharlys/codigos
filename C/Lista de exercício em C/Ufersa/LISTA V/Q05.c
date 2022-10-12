#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

/* 5. Faça um programa que solicita e lê dois números, calcula e exibe o dobro do
primeiro e o triplo do segundo. */

int main()
{
    setlocale(LC_ALL,"");

    float n1, n2;

    printf("Digite dois números quaisquer\n");
    scanf("%f %f", &n1, &n2);

    printf("%.1f é o Dobro de %.1f\n%.2f é o TRIPLO de %.2f\n\n", n1=n1*2, n1, n2=n2*3, n2);

    system("pause");
    return 0;
}