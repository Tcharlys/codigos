#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale (LC_ALL, " ");
    
    int idade, i;

    for (i=0 ; i<10 ; i++)
    {
        printf("Digite sua idade\n");
        scanf("%d", &idade);

        if (idade>=18)
        {
            printf("\n>>>Você é MAIOR de idade\n\n");
        }
        else
        {
            printf("\n>>>Você é MENOR de idade\n\n");
        }
    }

    return 0;
}