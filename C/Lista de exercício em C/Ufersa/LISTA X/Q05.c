#include <stdio.h>
#include <locale.h>

/* 5. Crie um programa que solicita e armazena n × m números inteiros em uma matriz n
× m, denominada de A, onde n e m também devem ser fornecidos pelo usuário.
Construa outra matriz, denominada de B, do mesmo tipo e tamanho de A, onde cada
elemento de B deve ser definido pela multiplicação do elemento correspondente de
A por 3, ou seja, B[i][j] deve ser igual a A[i][j] * 3, onde i e j correspondem aos
índices das matrizes. Dessa forma, se 
A = [ 3 2 1
      4 0 5
      8 6 9 ]
, teremos 
B = [ 9 6 3
    12 0 15
    24 18 27 ].
Ao final, o programa deve exibir o conteúdo de A e B. */

int main()
{
    setlocale(LC_ALL, " ");

    int i, j, n, m;

    printf("Digite a quantidade de linhas da matriz\n");
    scanf(" %d", &n);

    printf("Digite a quantidade de colunas da matriz\n");
    scanf(" %d", &m);

    int A[n][m], B[n][m];

    printf("informe os números\n");
    
    for ( i = 0; i < n; i++)
    {    
        for ( j = 0; j < m; j++)
        {
            scanf(" %d", &A[i][j]);
        }   
    }
    
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < m; j++)
        {
            B[i][j]=A[i][j]*3;
        }
    }
    
    printf(" Matriz A\n");

    for ( i = 0; i < m; i++)
    {
        for ( j = 0; j < m; j++)
        {
            printf(" %d", A[i][j]);
        }
        printf("\n");
    }
    
    printf(" Matriz B\n");

    for ( i = 0; i < m; i++)
    {
        for ( j = 0; j < m; j++)
        {
            printf(" %d", B[i][j]);
        }
        printf("\n");
    }
    
    getchar();
    return(0);
}