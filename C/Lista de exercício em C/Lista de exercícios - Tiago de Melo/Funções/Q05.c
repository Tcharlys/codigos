#include <stdio.h>
#include <locale.h>
#include <math.h>

/* 5. Escreva uma função para verificar se a raiz quadrada de um número inteiro é exata ou não. */

int verificaRaiz( int n)
{
    float raiz;

    raiz=n*n;

    if ( ceil(n)==n)
    {
        return (1);
    }
    else
    {
        return (0);
    }
    
}

int main()
{
    setlocale(LC_ALL, " ");

    int n, resposta;

    printf("\tRAIZ QUADRADA\n");
    printf("Digite um número\n");
    scanf(" %d", &n);

    resposta=verificaRaiz(n);

    if (resposta == 1)
    {
        printf("Raiz Quadrada de %d é exata\n\n", n);
    }

    else
    {
        printf("Raiz Quadrada de %d não é exata\n\n", n);
    }
    
    getchar();
    return (0);
}