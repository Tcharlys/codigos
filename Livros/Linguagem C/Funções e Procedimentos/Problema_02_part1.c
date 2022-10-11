#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

linha()
{
    int i;

    for ( i=1; i<=20; i++)
    {
        printf("*");
    }
    
    printf("\n");
}

int main()
{
    setlocale(LC_ALL, " ");

    int n;

    linha();

    printf("Números entre 1 e 5\n");

    linha();

    for ( n=1 ; n<=5; n++)
    {
        printf("%d\n", n);
    }

    linha();
    
    system("pause");
    return (0);
}