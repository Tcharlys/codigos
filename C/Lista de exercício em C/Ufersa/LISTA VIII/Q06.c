#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* 6. Elabore uma função, com retorno, que calcula a área de uma circunferência. Para
isto, utilize a seguinte fórmula:
𝐴 = 𝜋𝑟 2
Obs.: o valor do raio deve ser fornecido pelo usuário e deve ser passado como
argumento para a função. A função main deve receber e exibir o resultado do
cálculo. */

float circuferencia(float raio)
{
    float area=3.14159*(raio*raio);

    return (area);
}

int main()
{
    setlocale(LC_ALL, " ");

    float raio, area_main;

    printf("Digite um valor de raio qualquer\n");
    scanf(" %f", &raio);

    area_main=circuferencia(raio);

    printf("A Área da Circuferência -> %.2f", area_main);

    system("pause");
    return (0);
}