#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, " ");

    float n; 
    int cont=0;

    do
    {
        printf("Digite um número qualquer\n");
        scanf(" %f", &n);

        if ((n>=100) && (n<=200))
        {
            cont++;
        }

    } while (n!=0);

    printf("\nEncerrando execução.\nAnalisando os números...\n");
    printf("Números entre 100-> (%d) <-200\n", cont);
    
    system("pause");
    return (0);
}