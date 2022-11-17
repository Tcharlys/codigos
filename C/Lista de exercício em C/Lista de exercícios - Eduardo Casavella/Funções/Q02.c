#include <stdio.h>
#include <locale.h>

/* Crie um programa em C que leia dois números inteiros e uma função que receba esses valores e retorne
apenas o maior deles.*/

maior_menor( int n1, int n2)
{
    if (n1>n2)
    {
        return(n1);
    }
    else
    {
        return(n2);
    }
    
}

int main()
{
    setlocale(LC_ALL, " ");

    int n1, n2, res;

    printf("Digite dois números inteiros\n");
    scanf(" %d %d", &n1, &n2);

    res=maior_menor(n1, n2);

    printf("O maior é %d\n", res);
    
    return(0);
}