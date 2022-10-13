#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* 1. Implemente uma função, sem retorno, que recebe um valor inteiro por parâmetro e
informa se é, ou não, igual a zero. */

igualazero( int n )
{
    if (n==0)
    {
        printf("O número digitado é igual a 0\n");
    }
    else
    {
        printf("O número digitado não é igual a 0\n");
    }
    
}

int main()
{
    setlocale(LC_ALL, " ");

    int n;

    printf("Digite um número\n");
    scanf(" %d", &n);

    igualazero(n);

    system("pause");
    return (0);
}