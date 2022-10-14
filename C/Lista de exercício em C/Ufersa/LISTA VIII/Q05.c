#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* 5. Construa uma função, sem retorno, que recebe um valor inteiro por parâmetro e
informa se ele é, ou não, múltiplo de 5. */

int main()
{
    setlocale(LC_ALL, " ");

    int n;

    printf("Digite um número\n");
    scanf(" %d", &n);

    system("pause");
    return (0);
}