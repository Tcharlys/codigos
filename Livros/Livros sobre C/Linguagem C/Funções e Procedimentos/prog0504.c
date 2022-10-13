#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* Escreva um programa que, recorrendo a três funções distintas, escreva na tela a seguinte saída:
***
*****
*******
*****
***
*/

linha3x()
{
    int i;

    for ( i=0 ; i<3 ; i++)
    {
        printf("*");
    }

    printf("\n");
    
}

linha5x()
{
    int i;

    for ( i=0 ; i<5 ; i++)
    {
        printf("*");
    }

    printf("\n");
    
}

linha7x()
{
    int i;

    for ( i=0 ; i<7 ; i++)
    {
        printf("*");
    }

    printf("\n");
    
}

int main()
{
    setlocale(LC_ALL, " ");

    linha3x();
    linha5x();
    linha7x();
    linha5x();
    linha3x();
    
    system("pause");
    return (0);
}