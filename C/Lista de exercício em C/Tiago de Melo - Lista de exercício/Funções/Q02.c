#include <stdio.h>
#include <locale.h>

/* 2. Escreva um programa para obter três notas e que calcule e exiba a sua média.
Use uma função para o cálculo da média. */

float media( float nota1, float nota2, float nota3)
{
    float resultado=(nota1 + nota2 + nota3)/3;

    return(resultado);
}

int main()
{
    setlocale(LC_ALL, " ");

    float nota1, nota2, nota3, resultado_main;

    printf("Qual a nota da 1ª Avaliação\n");
    scanf(" %f", &nota1);

    printf("Qual a nota da 2ª Avaliação\n");
    scanf(" %f", &nota2);

    printf("Qual a nota da 3ª Avaliação\n");
    scanf(" %f", &nota3);

    resultado_main=media(nota1, nota2, nota3);

    printf("Média -> %.2f\n", resultado_main);
    
    getchar();
    return (0);
}