#include <stdio.h>
#include <locale.h>

/* 12. Faça um programa para calcular o volume de uma caixa retangular. Para isto, utilize
a seguinte fórmula:
𝑣𝑜𝑙𝑢𝑚𝑒 = 𝑐𝑜𝑚𝑝𝑟𝑖𝑚𝑒𝑛𝑡𝑜 × 𝑙𝑎𝑟𝑔𝑢𝑟𝑎 × 𝑎𝑙𝑡𝑢𝑟𝑎
Os valores do comprimento, da largura e da altura devem ser fornecidos pelo
usuário. */

int main()
{
    setlocale(LC_ALL,"");

    double comprimento, largura, altura, volume;

    printf("\t<<<VOLUME DE UM RETÂNGULO>>>\nDigite o comprimento\n");
    scanf("%lf", &comprimento);

    printf("\nDigite a largura\n");
    scanf("%lf", &largura);

    printf("\nDigite a altura\n");
    scanf("%lf", &altura);

    volume=comprimento*largura*altura;

    printf("O Volume da caixa -> %.2lf\n\n", volume);

    system("pause");
    return 0;
}