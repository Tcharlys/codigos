#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* 9. Crie uma função, com retorno, que recebe três notas por parâmetro e calcula a
média aritmética de um aluno. Crie outra função, sem retorno, que recebe a média
aritmética por parâmetro e informar o conceito obtido pelo aluno, de acordo com a
tabela a seguir:
Média       Conceito
>= 9            A
>= 7 e < 9      B
>= 6 e < 7      C
>= 4 e < 6      D
<4              E */

float media( float n1, float n2, float n3)
{
    float resultado=(n1+n2+n3)/3;

    return (resultado);
}

conceito( float resultado_main)
{
    if (resultado_main >= 9)
    {
        printf("Média -> %.2f\nConceito -> A\n", resultado_main);
    }
    
    if ((resultado_main >= 7) && (resultado_main < 9))
    {
        printf("Média -> %.2f\nConceito -> B\n", resultado_main);    
    }
    
    if ((resultado_main >= 6) && (resultado_main < 7))
    {
        printf("Média -> %.2f\nConceito -> C\n", resultado_main);
    }
    
    if ((resultado_main >= 4) && (resultado_main < 6))
    {
        printf("Média -> %.2f\nConceito -> D\n", resultado_main);
    }
    
    if (resultado_main < 4)
    {
        printf("Média -> %.2f\nConceito -> E\n", resultado_main);    
    }
    
}

int main()
{
    setlocale(LC_ALL, " ");

    float n1, n2, n3, n,resultado_main;

    printf("Digite a nota 1\n");
    scanf(" %f", &n1);

    printf("Digite a nota 2\n");
    scanf(" %f", &n2);

    printf("Digite a nota 3\n");
    scanf(" %f", &n3);

    resultado_main=media( n1, n2, n3);

    conceito(resultado_main);

    system("pause");
    return (0);
}