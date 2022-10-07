#include <stdio.h>
#include <locale.h>

int main()
{

    int i;
    float  peso=0, media_peso;

    for ( i=1 ; i<=50 ; i++)
    {
        printf("Informe o peso da pessoa %d\n", i);
        scanf(" %f", &peso);

        peso=peso+peso;
        media_peso=(peso/50);
    }
        printf("\nMédia de peso do grupo %.2f\n", media_peso);
    

    return 0;
}