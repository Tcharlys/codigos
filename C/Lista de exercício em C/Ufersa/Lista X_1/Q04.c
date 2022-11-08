#include <stdio.h>
#include <locale.h>

/* 4. Elabore programa que solicita e armazena oito números reais em uma matriz 4 × 2,
denominada de A. Construa outra matriz, denominada de B, do mesmo tipo e
tamanho de A, e com os mesmos elementos armazenados em A, porém de forma
invertida. Ou seja, o primeiro elemento de A passa a ser o último de B, o segundo
elemento de A passa a ser o penúltimo de B e assim por diante. Ao final, o
programa deve exibir o conteúdo de A e B.
*/

int main()
{
    setlocale(LC_ALL, " ");

    int linha, coluna, linha1=0, coluna1=0;
    float A[4][2], B[4][2];    

    for ( linha = 0; linha < 4; linha++)
    {
        for ( coluna = 0; coluna < 2; coluna++)
        {
            scanf(" %f", &A[linha][coluna]);
        }
    }
    
    for ( linha = 3; linha >= 0; linha--)
    {
        coluna1=0;

        for ( coluna = 1; coluna >= 0; coluna--)
        {
           B[linha1][coluna1]=A[linha][coluna];

           coluna1++; 
        }
    linha1++;
    }

    printf("\nMatriz A\n");

    for ( linha = 0; linha < 4; linha++)
    {
        for ( coluna = 0; coluna < 2; coluna++)
        {
            printf(" %.1f ", A[linha][coluna]);
        }
        printf("\n");
    }
    
    printf("\nMatriz B\n");
    
    for ( linha = 0; linha < 4; linha++)
    {
        for ( coluna = 0; coluna < 2; coluna++)
        {
            printf(" %.1f ", B[linha][coluna]);
        }
        printf("\n");
    }
    
    return(0);
}