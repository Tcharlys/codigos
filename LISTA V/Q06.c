#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

/* 6. Faça um programa que solicita e lê temperatura em Fahrenheit, faz a conversão para
Celsius e exibe tal resultado. Para isto, utilize a seguinte fórmula:
𝐶 = (𝐹 − 32)/1,8 */

int main()
{
    setlocale(LC_ALL,"");

    float celsius, fahrenheit;

    printf("Informe uma temperatura em graus Fahrenheit (ºf)\n");
    scanf("%f", &fahrenheit);

    celsius=(fahrenheit-32)/1.8;

    printf("%.1f ºF -> %.1f ºC\n", fahrenheit, celsius);

    system("pause");
    return 0;
}