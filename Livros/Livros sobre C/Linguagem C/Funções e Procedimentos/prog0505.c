#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

linha( int num)
{
    int i;

    for ( i=0 ; i<num; i++)
    {
        printf("*");
    }
    
    printf("\n");
}

int main()
{
    setlocale(LC_ALL, " ");

    linha(3);
    linha(5);
    linha(7);
    linha(5);
    linha(3);

    system("pause");
    return (0);
}