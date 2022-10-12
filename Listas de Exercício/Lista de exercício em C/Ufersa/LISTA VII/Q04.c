#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale (LC_ALL, " ");
    
    int i, quantidade=0;

    for ( i=10 ;(i>=10), (i<=50) ; i++)
    {
        if (i%2==0)
        {
            printf("Número difisível por 2 -> %d\n", i);

            quantidade=quantidade+1;
            
            printf("Quantidade de Nº divisíveis por 2 -> %d\n\n", quantidade);
        }

    }
    
    return 0;
}