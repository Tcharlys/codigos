#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* 3. Faça uma função, sem retorno, que recebe um valor inteiro por parâmetro, verifica e 
informa se tal número é par ou ímpar. */

par_impar( int n )
{
    if (n%2==0)
    {
        printf("O Nº digitado é PAR\n");
    }
    else if (n%2!=0)
    {
        printf("O Nº digitado é ÍMPAR\n");
    }

}

int main()
{
    setlocale(LC_ALL, " ");

    int n;

    printf("Digite um número\n");
    scanf(" %d", &n);

    par_impar(n);

    system("pause");
    return (0);
}