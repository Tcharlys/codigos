#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale (LC_ALL, " ");
    
    int idade, i;

    for (i=0;i<=10;i++)
    {
        printf("Digite sua idade\n");
        scanf("%d", &idade);

            if (idade>=18)
            {
                printf("\nVocê é MAIOR de idade\n");
            }
            else
            {
                printf("\nVocê é MENOR de idade\n");
            }
    }

    return 0;
}