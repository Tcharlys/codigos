#include <stdio.h>
#include <locale.h>
#include <math.h>

/* 11. Elabore um programa que calcula a área de uma circunferência. Para isto, utilize a
seguinte fórmula:
𝐴 = 𝜋𝑟2
O valor do raio deve ser fornecido pelo usuário. */

int main()
{
    setlocale(LC_ALL,"");

    double raio, area;

    printf("\t<<< ÁREA DA CIRCUFERÊNCIA>>>\nDigite o raio\n");
    scanf("%lf", &raio);

    area=3.14159265359*pow(raio, 2);

    printf("\nA Área da circuferência -> %.2lf\n", area);

    system("pause");
    return 0;
}