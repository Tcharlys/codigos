#include <stdio.h>
#include <locale.h>

/* 3. Faça um programa que solicita e armazena seis números inteiros em uma matriz 2 x
3, denominada de A, e solicita e armazena seis números inteiros em outra matriz 2 x
3, denominada de B. Em seguida, exiba a soma dessas matrizes. */

int main()
{
    setlocale(LC_ALL, " ");

    int A[2][3], B[2][3], linha, coluna, soma=0;

    for ( linha = 0; linha < 2; linha++)
    {
        for ( coluna = 0; coluna < 3; coluna++)
        {
            scanf(" %d", &A[linha][coluna]);
        }
    }
    
    for ( linha = 0; linha < 2; linha++)
    {
        for ( coluna = 0; coluna < 3; coluna++)
        {
            scanf(" %d", &B[linha][coluna]);
        }
    }

    for ( linha = 0; linha < 2; linha++)
    {
        for ( coluna = 0; coluna < 3; coluna++)
        {
            soma=A[linha][coluna] + B[linha][coluna];
            
            printf(" A[%d][%d] => %d + B[%d][%d] => %d -> Soma = %d\n", linha, coluna, A[linha][coluna], linha, coluna, B[linha][coluna], soma);
        }

    }

    return(0);
}