#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* 8. Elabore uma função, com retorno, que recebe um valor inteiro maior ou igual a zero
por parâmetro e retorna o fatorial de tal número. */

fatorial( int n)
{
    int i, resultado=1;

    for ( i=n; i>1; i--)
    {
        resultado=i*resultado;
    }
    
    return (resultado);
}

int main()
{
    setlocale(LC_ALL, " ");

    int n, resultado_main;

    do
    {
        printf("Digite um número inteiro maior ou igual a zero\n");
        scanf(" %d", &n);

        resultado_main=fatorial(n);

        printf("%d! = %d\n", n, resultado_main);
        
    } while (n>=0);
    



    system("pause");
    return (0);
}