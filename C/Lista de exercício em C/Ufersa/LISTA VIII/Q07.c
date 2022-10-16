#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* 7. Faça uma função, com retorno, para calcular o valor do volume de uma caixa
retangular, utilizando a seguinte fórmula:
𝑣𝑜𝑙𝑢𝑚𝑒 = 𝑐𝑜𝑚𝑝𝑟𝑖𝑚𝑒𝑛𝑡𝑜 × 𝑙𝑎𝑟𝑔𝑢𝑟𝑎 × 𝑎𝑙𝑡𝑢𝑟𝑎
Obs.: os valores do comprimento, da largura e da altura devem ser fornecidos pelo
usuário e devem ser passados como argumento para a função. A função main deve
receber e exibir o resultado do cálculo. */

volume( float comprimento, float altura, float largura)
{
    float resultado=comprimento*largura*altura;

    return(resultado);
}

int main()
{
    setlocale(LC_ALL, " ");

    float altura, largura, comprimento, resultado_main;

    printf("Informe o COMPRIMENTO, a ALTURA, e a LARGURA (Metros)\n");
    scanf(" %f %f %f", &comprimento, &altura, &largura);

    resultado_main=volume(comprimento, altura, largura);

    printf("O Volume da Caixa -> %.2f", resultado_main);
    
    system("pause");
    return (0);
}