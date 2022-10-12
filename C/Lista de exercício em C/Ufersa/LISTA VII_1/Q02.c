#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, " ");

    int n, i, soma, negativo=0;

    for( i=1 ; i<=20 ; i++)
    {
        printf("Digite um número\n");
        scanf(" %d", &n);

        if (n>0)
        {
            soma=n+n;
        }
        
        if (n<0)
        {
            negativo++;
        }
        
    }
    
    printf("Soma dos números positivos -> %d\n", soma);
    printf("Quantidade de números negativos -> %d\n", negativo);
    
    return 0;
}