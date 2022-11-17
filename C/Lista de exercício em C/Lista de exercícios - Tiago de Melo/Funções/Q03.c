#include <stdio.h>
#include <locale.h>

/* 3. Crie uma função que converta graus para radianos e outra função que converta radianos para graus.
Fazer um aplicativo para testar as funções. */

float g_radianos( float graus)
{
    float radiano;

    radiano = graus*(3.14159/180);

    return(radiano);
}

g_graus(float radianos)
{
    float grau;

    grau = radianos * (180/3.1459);

    return(grau);
}

int main()
{
    setlocale(LC_ALL, " ");

    int opcao, resposta_final;
    float graus, radianos, resultado_gradianos, resultado_ggraus;

    do
    {
        printf("\tCONVERSOR DE GRAUS E RADIANOS\n");
        printf("Qual você vai converter?\n");
        printf("1 GRAUS -> RADIANOS\n0 RADIANOS -> GRAUS\n");
        scanf(" %d", &opcao);

        if (opcao==1)
        {
            printf("Informe um valor em GRAU.\n");
            scanf(" %f", &graus);

            resultado_gradianos = g_radianos(graus);
            
            printf("%.2f° -> %.5frad\n\n", graus, resultado_gradianos);
        }

        if (opcao==0)
        {
            printf("Informe um valor em RADIANOS\n");
            scanf(" %f", &radianos);

            resultado_ggraus = g_graus(radianos);
            
            printf("%.2frad -> %.5f°\n\n", radianos, resultado_ggraus);
        }
    
    

        printf("Deseja converter outro de novo?\n");
        printf("1 SIM\t\t0 NÃO\n");
        scanf(" %d", &resposta_final);

    } while (resposta_final != 0);

    getchar();
    return (0);
}