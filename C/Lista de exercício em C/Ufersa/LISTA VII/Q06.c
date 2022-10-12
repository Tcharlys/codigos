#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale (LC_ALL, " ");

    int n, i, divisores=0;

    printf("Informe um número inteiro qualquer\n");
    scanf("%d", &n);

    printf("divisores de %d\n", n);
    
    for ( i=2 ; i<=(n/2) ; i++)
    {

        if (n%i==0)
        {
            printf("%d\n", i);
            divisores++;
        }
    }

    puts("");
    
    if (divisores!=0)
    {
        printf("%d não é primo\n\n", n);
    }
    else
    {
        printf("%d é primo\n\n", n);
    }
        
    return 0;
}