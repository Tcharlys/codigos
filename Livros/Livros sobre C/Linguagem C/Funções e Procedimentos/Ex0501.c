#include <stdio.h>
#include <locale.h>

/* Escreva uma função que calcule qual a maior de dois inteiros. */

int maior( int n1, int n2)
{
    if (n1>n2)
    {
        return (n1);
    }
    
    else
    {
        return (n2);
    }
    
}

int main()
{
    setlocale(LC_ALL, " ");

    int n1, n2, resposta;

    printf("Digite dois números inteiros\n");
    scanf(" %d %d", &n1, &n2);

    resposta=maior(n1, n2);

    printf("%d é maior\n", resposta);

    getchar();
    return (0);
}