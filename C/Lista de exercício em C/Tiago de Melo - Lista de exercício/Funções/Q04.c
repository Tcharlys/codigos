#include <stdio.h>
#include <locale.h>

/* 4. Escreva a função void somaInteiros(int a, int b, int c), que soma os três valores
passados como argumento e imprime o resultado da soma na tela. Faça um programa que chame
a função somaInteiros dentro da função principal. */

void somaInteiros( int a, int b, int c)
{
    int soma;

    soma=a + b + c;

    printf("Soma -> %d", soma);
}

int main()
{
    setlocale(LC_ALL, " ");

    int a, b, c;

    printf("Digite três números naturais\n");
    scanf(" %d %d %d", &a, &b, &c);

    somaInteiros(a, b, c);

    getchar();
    return (0);
}