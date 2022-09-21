#include <stdio.h>
#include <locale.h>
#include <math.h>

/* 10. Você foi procurado por uma nutricionista para automatizar o cálculo do Índice de
Massa Corpórea (IMC) de seus pacientes. Para isto, crie um programa que solicita e
lê o peso e a altura de uma pessoa e apresenta seu IMC com duas casas decimais
após a vírgula. O IMC é calculado por meio da seguinte fórmula:
𝐼𝑀𝐶 =𝑝𝑒𝑠𝑜/(𝑎𝑙𝑡𝑢𝑟𝑎2) */

int main()
{
    setlocale(LC_ALL,"");

    float peso, altura, imc;

    printf("\t<<<Índice de Massa Corpórea (IMD)>>>\nInforme o peso (Kg) do paciente\n");
    scanf("%f", &peso);

    printf("\nDigite a altura (Metros) do paciente\n");
    scanf("%f", &altura);

    imc=peso/pow(altura, 2);

    printf("\nIMC do paciente -> %.2f", imc);

    system("pause");
    return 0;
}