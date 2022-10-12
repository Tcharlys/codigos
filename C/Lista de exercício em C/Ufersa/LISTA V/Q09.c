#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

/* 9. A cotação do dólar influencia na economia brasileira e muitos economistas se
encarregam de calcular, muitas vezes de forma manual, o valor do real em dólar.
Você foi contratado por um economista para automatizar a conversão de reais em
dólares. Crie um programa que solicita e lê a cotação do dólar atual e o valor em real
a ser convertido e, em seguida, calcula e exibe o resultado da conversão. */

int main()
{
    setlocale(LC_ALL,"");

    double dolar, real;

    printf("<<<\tCONVERSOR DE DOLAR PARA REAL>>>\nDigite a cotação do dolar ($) hoje\n");
    scanf("%lf", &dolar);

    printf("\nInforme a quantidade em real(R$) a ser convertida\n");
    scanf("%lf", &real);

    dolar=real/dolar;

    printf("\n%.2lf R$ = %.2lf$\n\n", real, dolar);

    system("pause");
    return 0;
}