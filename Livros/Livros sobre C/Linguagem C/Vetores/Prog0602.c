#include <stdio.h>
#include <locale.h>

/* Suponhamos, as seguintes declarações
    int v[10];
    int x[20];
Suponhamos, então, que é nossa intenção iniciar os vetores v e x com o valor ZERO em todas
as posições, e que pretenderíamos utilizar uma função tal para realizar tal carga inicial.
*/

void zerarV(int v[10]);

void zerarX(int x[20]);

int main()
{
    setlocale(LC_ALL, " ");

    int v[10], x[20];

    zerarV(v);
    //zerarv(v[10]);
    
    zerarX(x);
    //zerarX(x[20]);

    getchar();
    return (0);
}

void zerarV( int v[10])
{
    int i;

    for ( i = 0; i < 10; i++)
    {
        v[i]=0;
    }
}

void zerarX( int x[20])
{
    int i;
    for ( i = 0; i < 20; i++)
    {
        x[i]=0;
    }   
}