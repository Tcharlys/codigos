#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

asteriscos( int num )
{
    int i;

    for ( i=0 ; i<num ; i++)
    {
        printf("*");
    }
    
    printf("\n");

}

int main()
{
    setlocale(LC_ALL, " ");

    int num1, num2, num3;

    printf("Informe a quantidade de astericos a serem exibiddos na 1ª Linha\n");
    scanf(" %d", &num1);

    printf("Informe a quantidade de astericos a serem exibiddos na 2ª Linha\n");
    scanf(" %d", &num2);

    printf("Informe a quantidade de astericos a serem exibiddos na 3ª Linha\n");
    scanf(" %d", &num3);
    
    asteriscos( num1 );
    asteriscos( num2 );
    asteriscos( num3 );
    

    system("pause");
    return (0);
}