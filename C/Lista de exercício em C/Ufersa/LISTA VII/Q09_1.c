#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale (LC_ALL, " ");
    
    int x, y, n, d, divisores=0;

    printf("Informe dois Nº NATURAIS > 0\n");
    scanf(" %d %d", &x, &y);
    
    for ( n=x ; n<=y ; n++, divisores=0)
    {
        for ( d=1 ; d<=n ; d++)
        {
            if (n%d==0)
            {
                divisores++;
            }
        }

        if (divisores==2)
        {
            printf("%d\n", n);
        }
    }
    
    
    return 0;
}