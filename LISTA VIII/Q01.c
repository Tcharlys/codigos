#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

igualazero()
{
    int n;

    printf("Digite um número\n");
    scanf(" %d", &n);

    if (n=0)
    {
        printf("O número digitado é igual a 0\n");
    }
    else
    {
        printf("O número digitado não é igual a 0\n");
    }
    
}

int main()
{
    setlocale(LC_ALL, " ");

    igualazero();

    system("pause");
    return (0);
}