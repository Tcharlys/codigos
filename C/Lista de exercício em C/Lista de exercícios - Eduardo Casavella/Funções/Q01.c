#include <stdio.h>
#include <locale.h>

/* 1. Crie um programa em C que receba um número inteiro e uma função que retorne 1 se o número digitado
for positivo ou retorne zero se o número for negativo. */

retorne1( int n)
{
    int x=n;

    if(x > 0)
    {
        return(0);
    }

    if (x < 0)
    {
        return(1);
    }
    
}

int main()
{
    setlocale(LC_ALL, " ");

    int n, res;

    printf("Digite um número\n");
    scanf(" %d", &n);

    res=retorne1(n);

    if (res == 0)
    {
        printf(" %d é positivo\n", n);
    }

    else if ( res == 1)    
    {
        printf(" %d é negativo\n", n);
    }

    return(0);
}