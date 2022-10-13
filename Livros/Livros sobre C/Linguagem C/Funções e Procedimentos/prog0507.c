#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* Escreva um programa que solicite dois números ao usuário e apresente na tela o resultado da sua
soma e o dobro de cada um deles. */

float soma( float n1, float n2)
{

    return ( n1+n2 );
}

float dobro( float n )
{
    return( n
    
    *2 );

}
int main()
{
    setlocale(LC_ALL, " ");

    float n1, n2, resultado_soma;

    printf("Digite dois números quaisquer\n");
    scanf(" %f %f", &n1, &n2);

    soma(n1, n2);

    resultado_soma=soma(n1, n2);

    printf("%.1f + %.1f = %.1f\n", n1, n2, resultado_soma);
    printf("%.1f * 2= %.1f\n", n1, dobro(n1));
    printf("%.1f * 2= %.1f\n", n2, dobro(n2));

    system("pause");
    return (0);
}