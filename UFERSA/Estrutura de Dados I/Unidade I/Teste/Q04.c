#include <stdio.h>

int somatorio( int n1, int n2)
{
    int n = 0, i;

    for ( i = 0; i < n2; i++)
    {
        if ((i > n1) && (i <n2))
        {
            i+=i;
        }
        
    }
    
    return (i);
}

int main()
{
    int n1 = 2, n2 = 6, soma;

    soma = somatorio( n1, n2);

    printf("Somatório -> %d\n", soma);

    return 0;
}