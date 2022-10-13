#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* Altere o progrma anterior de forma que a função linha escreva qualquer caractere, e não apenas
o caractere asterisco. */

linha( char caractere, int num)
{
    int i;

    for ( i=0; i< num; i++)
    {
        printf("%c", caractere);
    }

    printf("\n");
    
}
int main()
{
    setlocale(LC_ALL, " ");

    char caractere;
    int num;

    printf("Informe o caractere a ser exibido na tela\n");
    scanf(" %c", &caractere);

    printf("Informe a quantidade de vezes que este ( %c )caractere vai se repetir\n", caractere);
    scanf(" %d", &num);

    linha( caractere, num);

    system("pause");
    return (0);
}