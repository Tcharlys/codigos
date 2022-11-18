#include <stdio.h>
#include <locale.h>

/* 4. Escreva um programa que solicita e armazena dez números inteiros em um vetor e,
ao final, informa o maior valor encontrado no vetor. */

int main()
{
    setlocale(LC_ALL, " ");

    int e[10], i, maior;

    printf("Digite 10 números inteiros\n");

    for ( i = 0; i < 10; i++)
    {
        scanf(" %d", &e[i]);
    }
    
    maior=e[0];    
        
    for ( i = 1; i < 10; i++)
    {
        if (e[i] > maior)
        {
            maior=e[i];
        }
    }
    
    printf("\nO maior valor digitado foi %d\n", maior);

    return(0);
}