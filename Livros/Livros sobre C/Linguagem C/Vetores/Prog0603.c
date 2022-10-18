#include <stdio.h>
#include <locale.h>

/* Escreva uma função que inicie qualquer vetor de inteiros. */

void zerarV( int v[], int n);

int main()
{
    setlocale(LC_ALL, " ");

    int n, v[10], x[20];

    zerarV(v, 10);
    zerarV(v, 20);

    getchar();
    return (0);
}

void zerarV( int v[], int n)
{
    int i;

    for ( i = 0; i < n; i++)
    {
        v[i]=0;
    }
}