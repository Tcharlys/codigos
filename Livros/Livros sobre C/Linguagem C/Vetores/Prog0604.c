#include <stdio.h>
#include <locale.h>

/* */

void inicia( int v[]);

int main()
{
    setlocale(LC_ALL, " ");

    int i, v[10], cont, x[20];

    inicia(v);

    printf("->INICIANDO O VETOR v...\n");

    for ( i = 0; i < 10; i++)
    {
        v[i]=0;

        printf(" %d\n", v[i]);
    }
    
    printf("->INICIANDO O VETOR x...\n");

    for ( cont = 0; cont < 20; cont++)
    {
        x[i]=0;

        printf(" %d\n", x[i]);
    }
    
    getchar();
    return (0);
}

void inicia( int s[])
{
    int i;

    for ( i = 0; i < 69; i++)
    {
        s[i];

        printf(" %d\n", s[i]);
    }
}