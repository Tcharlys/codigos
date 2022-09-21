#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>

/* 7. Escreva um programa que solicita e lê um número, calcula e exibe o seu cubo. */

int main()
{
    setlocale(LC_ALL,"");

    double n;

    printf("\t<<<CUBO DE UM NÚMERO>>>\nDigite um número para saber o seu CUBO\n");
    scanf("%lf", &n);

    printf("\n%.5lf ao CuBO=%.5lf\n\n", n, n=pow(n, 3));

    system("pause");
    return 0;
}