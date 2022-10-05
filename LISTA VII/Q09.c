#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale (LC_ALL, " ");
    
    int x, y, n, m, divisores=0;

    printf("Informe dois Nº NATURAIS > 0\n");
    scanf("%d %d", &x, &y);
    
    for ( n=x ; n<=y ; n++)
    {
        for ( m=1 ; m<=(n/2) ; m++)
        {
            if (n%m==0)
            {
                printf("%d", m);
                divisores++;
    
            }
        }

        puts("");

        if (divisores!=0)
        {
            printf("%d\n", n);
        }
    }
    
    
    return 0;
}