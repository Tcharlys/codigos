#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale (LC_ALL, " ");

    int n, i, cont, fatorial=1;

    for ( i=1 ; i<=11 ; i++)
    {
        if (i%2==1)
        {
            for ( cont=i ; cont>=1 ; cont--)
            {
                fatorial*=cont;
            }

            printf("%d!=%d\n", i, fatorial);
            
            fatorial=1;
        }
    }
        
    return 0;
}