#include <stdio.h>

int soma( int n1, int n2)
{
    int resultado_soma=n1+n2;

    return(resultado_soma);
}

int main()
{
    
    int n1, n2, resultado_main;

    printf("Difgite dos valores\n");
    scanf(" %d %d", &n1, &n2);

    resultado_main=soma(n1, n2);

    printf("%d + %d = %d", n1, n2, resultado_main);

    return 0;
}