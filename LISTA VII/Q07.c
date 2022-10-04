#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale (LC_ALL, " ");

    int n, i, fatorial=1;

    printf("Informe um número qualquer\n\n");
    scanf("%d", &n);    
    
    while (n>=0)
    {
        for (i=n ; i>=0 ; --i)
        {
            fatorial=fatorial*i;
        }
    }
        if (n>=0)
        {
            printf("\n%d!=%d\n\n", n, fatorial);
        }
        else
        {
            printf("\nNão existe fatorial de número negativo\n\n");
        }
    
    return 0;
}