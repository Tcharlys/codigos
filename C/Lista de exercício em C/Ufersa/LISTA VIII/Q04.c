#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* 4. Faça uma função, sem retorno, que recebe a idade do usuário por parâmetro, verifica 
e informa se ele é maior de idade ou não. */

idade()
{
    int idade;

    printf("Quantos anos você tem?\n");
    scanf(" %d", &idade);

    if (idade>=18)
    {
        printf("Você é MAIOR de idade.\n");
    }
    else if (idade<18)
    {
        printf("Você é MENOR de idade.\n");
    }
    
}

int main()
{
    setlocale(LC_ALL, " ");

    idade();

    system("pause");
    return (0);
}