#include <stdio.h>

int main()
{
    char nome [99];
    float salariofixo, salariototal;

    printf("Digite o seu npme\n");
    scanf("%s", nome);

    printf("Informe seu salário fixo R$\n");
    scanf("%f", &salariofixo);

    salariototal=salariofixo*0.15;

    printf("\nFUNCIONÁRIO: %s\nTOTAL = R$ %.2f\n\n", nome,  salariototal);

    return 0;
}