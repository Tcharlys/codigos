#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* Escreva um programa que coloque uma linha com 20 asteriscos na tela */

int main()
{
    setlocale(LC_ALL, " ");

    int i;

    for ( i=1; i<=20; i++)
    {
        putchar('*');
    }
    
    putchar('\n');

    system("pause");
    return (0);
}