#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* 1. Escreva uma função que receba dois números inteiros retorne o menor número. */

menor(int n1, int n2)
{
    if (n1 < n2)
    {
        printf(" %d é menor que %d\n", n1, n2);
    }

    else if (n2 < n1)
    {
        printf(" %d é menor que %d\n", n2, n1);
    }
    else
    {
        printf(" %d é igual a %d\n", n1, n2);
    }
    

}

int main()
{
    setlocale(LC_ALL, " ");

    int n1, n2;
    printf("Digite dois números inteiros\n");
    scanf(" %d %d", &n1, &n2);

    menor(n1, n2);

    system("pause");
    return(0);
}