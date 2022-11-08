#include <stdio.h>
#include <locale.h>

/* 2. Elabore um programa que solicita e armazena 3 notas de 5 alunos em uma matriz 5
x 3. Por fim, calcula e exibe a média aritmética obtida por cada aluno.
*/

int main()
{
    setlocale(LC_ALL, " ");

    int linha, coluna;
    float aluno[5][3], media=0, res=0;

    for( linha=0; linha < 5; linha++)
    {
        for( coluna=0; coluna < 3; coluna++)
        {
            scanf(" %f", &aluno[linha][coluna]);
        }
    }

    for ( linha=0; linha < 5; linha++)
    {
        for( coluna=0; coluna < 3; coluna++)
        {
            media=aluno[linha][coluna] + media;
        }

        res=media/3;

        printf(" Média aritmética do aluno %d = %.2f\n", linha+1, res);
    }
    
    return(0);
}