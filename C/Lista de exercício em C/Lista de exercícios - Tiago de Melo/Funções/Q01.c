#include <stdio.h>
#include <locale.h>

/* 1. Escreva uma função desenha Quadrado que exibe um quadrado sólido (o mesmo número de linhas e colunas).
O caracter utilizando para preencher o quadrado e o valor do lado são passados como argumentos para a função.
Por exemplo, se o caracter for x e o valor do lado for 5, a função deverá exibir:

xxxxx

xxxxx

xxxxx

xxxxx

xxxxx
*/

quadrado( char caractere, int tamanho)
{
    int linha, coluna;
    char letra=caractere;

    for ( linha = 1; linha <= tamanho; linha++)
    {
        for ( coluna = 1; coluna <= tamanho; coluna++)
        {
            printf(" %c", letra);
        }

        printf("\n");
    }
    
}

int main()
{
    setlocale(LC_ALL, " ");

    char caractere; 
    int tamanho;

    printf("DESENHANDO UM QUADRADO\n");
    printf("Digite o caractere.\n");
    scanf(" %c", &caractere);

    printf("Informe qual será o tamanho do quadrado\n");
    scanf(" %d", &tamanho);

    quadrado(caractere, tamanho);

    getchar();
    return (0);
}