#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* 2. Crie uma função, sem retorno, que recebe um valor inteiro por parâmetro e informa 
se ele é positivo, negativo ou neutro. */

num()
{
    int n;

    printf("Digite um número qualquer\n");
    scanf(" %d", &n);

    if (n>0)
    {
        printf("O número digitado é POSITIVO\n");
    }
    else if (n==0)
    {
        printf("O número digitado é NEUTRO\n");
    }
    else
    {
        printf("O número digitado é NEGATIVO\n");
    }
    
    
}

int main()
{
    setlocale(LC_ALL, " ");

    num();

    system("pause");
    return (0);
}