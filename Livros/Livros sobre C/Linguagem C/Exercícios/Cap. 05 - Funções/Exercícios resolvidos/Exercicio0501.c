#include <stdio.h>
#include <locale.h>

/* Escreva a função x_isdigit, que verifica se um determinado caractere é digito ou não.
Escreva um programa de teste da função. */
int x_isdigit();

int main()
{
    setlocale(LC_ALL, " ");

    char tecla;

    printf("Aperte uma tecla do seu teclado\n");
    scanf(" %c", &tecla);

    x_isdigit(tecla);

    getchar();
    return(0);
}

int x_isdigit( char tecla)
{
    if (tecla )
    {
        /* code */
    }
    
}