#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

/* 4. Crie um programa que solicita e lê uma temperatura em Celsius, faz a conversão
para Fahrenheit e exibe tal resultado. Para isto, utilize a seguinte fórmula:
𝐹 = (𝐶 × 1,8) + 32 */

int main()
{
    setlocale(LC_ALL,"");

    float celsius, fahrenheit;

    printf("Informe uma temperatura em graus Celsius (ºC)\n");
    scanf("%f", &celsius);

    fahrenheit=(celsius*1.8)+32;

    printf("%.1f ºC -> %.1f ºF\n", celsius, fahrenheit);

    system("pause");
    return 0;
}