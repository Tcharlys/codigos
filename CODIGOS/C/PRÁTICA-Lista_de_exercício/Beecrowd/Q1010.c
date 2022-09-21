#include <stdio.h>

int main()
{
    int codigo1 , npeca1, codigo2, npeca2;
    float vpeca1, vpeca2, saldo;

    scanf("%d %d %f", &codigo1, &npeca1, &vpeca1);
    scanf("%d %d %f", &codigo2, &npeca2, &vpeca2);
    
    saldo=vpeca1+vpeca2;

    printf("VALOR A PAGAR: R$ %.2f", saldo);
    return 0;
}