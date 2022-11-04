#include <stdio.h>
#include <locale.h>

/* 1. Crie um programa que solicita e armazena doze números inteiros em uma matriz 3 x
4. Em seguida, exiba os elementos da matriz na ordem inversa. */

int main()
{
    setlocale(LC_ALL, " ");

    int m[3][4], linha, coluna; 

    for( linha=0; linha < 3; linha++)
    {
        for( coluna=0; coluna < 4; coluna++)
        {
            scanf(" %d", &m[linha][coluna]);
        }
    }

    for( linha=2; linha >= 0; linha--)
    {
        for( coluna=3; coluna >= 0; coluna--)
        {
            printf(" m[%d][%d]=%d\n", linha, coluna, m[linha][coluna]);
        }
    }
    
    return(0);
}