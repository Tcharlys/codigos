#include <stdio.h>
#include <locale.h>

int main(){

    setlocale(LC_ALL, " ");

    float A1, A2, A3, AF, MP, MF;

    printf("Digite a nota da 1ª avaliação\n");
    scanf("%f", &A1);

    printf("\nDigite a nota da 2ª avaliação\n");
    scanf("%f", &A2);

    printf("\nDigite a nota da 3ª avaliação\n");
    scanf("%f", &A3);
    
    MP=(A1+A2+A3)/3;

    if (MP>=7.0)
    {
        printf("\nMédia Parcial -> %.1f\nAPROVADO\n", MP);
    }
    else
    {
        if (MP<3.4)
        {
            printf("\nMédia Parcial -> %.1f\nREPROVADO\n", MP);
        }
    }
    if (MP>= 3.5 && MP<7.0)
    {
        printf("\nDigite a nota da avaliação final\n");
        scanf("%f", &AF);

        MF=((6*MP)+(4*AF))/10;

            if (MF>=5.0)
            {
                printf("\nMédia Final -> %.1f\nAPROVADO\n", MF);
            }
    }
    
    return 0;
}