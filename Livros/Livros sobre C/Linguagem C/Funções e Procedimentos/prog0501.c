#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* Escreva um programa que coloque na tela a seguinte saída, escrevendo a linha de 20 asteriscos através de um laço for. */

int main()
{
    setlocale(LC_ALL, " ");

    int i, n;

    for (i=1 ; i<=20 ; i++)
    {
        printf("*");
    }
    
    putchar('\n');

    printf("Números entre 1 e 5\n");

    for (i=1 ; i<=20 ; i++)
    {
        printf("*");
    }

    putchar('\n');

    for ( n=1; n<=5 ; n++)
    {            
        printf("%d\n", n);
    }

    for (i=1 ; i<=20 ; i++)
    {
        printf("*");
    }
    
    putchar('\n');

    system("pause");
    return (0);
    
}