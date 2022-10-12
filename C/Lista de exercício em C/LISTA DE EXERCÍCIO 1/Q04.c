#include<stdio.h>
#include<locale.h>

/* 4. Fazer um programa em "C" que pergunte um valor em graus Fahrenheit e
imprime no vídeo o correspondente em graus Celsius usando as fórmulas que
seguem.
a) Usar uma variável double para ler o valor em Fahrenheit e a fórmula
C=(f-32.0) * (5.0/9.0).
b) Usar uma variável int para ler o valor em Fahrenheit e a fórmula
C=(f-32)*(5/9). */

int main()
{

double afahrenheit, acelsius;
int bfahrenheit, bcelsius;

    printf("CONVERTER FAHRENHEIT(ºF) EM CELSIUS(ºC)\n");
    printf("A) Informe uma temperatura em Fahrenheit\n");
    scanf("%lf", &afahrenheit);

    acelsius=(afahrenheit-32.0)*(5.0/9.0);

    printf("\nA) %.2lfºF -> %.2lfºC", afahrenheit, acelsius);

    printf("\nB) Informe uma temperatura em Fahrenheit\n");
    scanf("%d", &bfahrenheit);

    bcelsius=(bfahrenheit-32)*(5/9);

    printf("\nB) %dºF -> %dºC", bfahrenheit, bcelsius);



    system("pause");
    return 0;
}