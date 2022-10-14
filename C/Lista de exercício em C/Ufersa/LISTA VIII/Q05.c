#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* 5. Construa uma função, sem retorno, que recebe um valor inteiro por parâmetro e
informa se ele é, ou não, múltiplo de 5. */

int multiplo( int n)
{
    if (n%5==0)
    {
        printf("Este Nº é múltiplo de 5\n");
    }

    else
    {
        printf("Este Nº não é múltiplo de 5\n");
    }
}

int main()
{
    setlocale(LC_ALL, " ");

    int n;

    printf("Digite um número\n");
    scanf(" %d", &n);

    multiplo(n);

    system("pause");
    return (0);
}