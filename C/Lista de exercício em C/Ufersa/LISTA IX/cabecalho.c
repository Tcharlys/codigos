#include <stdio.h>
#include <locale.h>

/* 1. Escreva um programa que solicita e armazena oito valores inteiros em um vetor,
denominado de A, e exibe os valores armazenados, porém na ordem inversa. */

int main()
{
    setlocale(LC_ALL, " ");

    int A[8], i;

    printf("Digite oito valores inteiros\n");

    for (i = 0; i <= 8; i++)
    {
        scanf(" %d", &A[i]);
    }
    
    for ( i = 0; i < count; i++)
    {
        /* code */
    }
    

    return (0);
}