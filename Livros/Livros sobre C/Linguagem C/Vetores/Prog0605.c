#include <stdio.h>
#include <locale.h>
#define NUM 69

const int num = 19;

/* */

void zera( int[]);

int main()
{
    setlocale(LC_ALL, " ");

    int i, v[11], x[22];

    zera(v);

    printf("INICIANDO O VETOR x...\n");

    for ( i = 0; i < NUM; i++)
    {
        x[i]=0;

        printf("x[%d] = %d\n", i, x[i]);
    }
    
    getchar();
    return (0);
}

void zera( int v[])
{
    int i;

    for ( i = 0; i < num; i++)
    {
        v[i]=0;

        printf("v[%d] = %d\n", i, v[i]);
    }
}
