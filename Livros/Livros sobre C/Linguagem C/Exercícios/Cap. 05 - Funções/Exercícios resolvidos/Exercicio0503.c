#include <stdio.h>
#include <locale.h>
#include <math.h>

/* Implemente a função:
        float Pot(float x, int n)
    Devolve o valor x^n:
        x^0=1.0
        x^2=x*x
*/

float Pot( float x, int n);

int main()
{
    setlocale(LC_ALL, " ");

    float x, resposta_main;
    int n;

    printf("CALCULANDO POTÊNCI\n");
    printf("Digite a BASE\n");
    scanf(" %f", &x);

    printf("Digite o EXPOENTE\n");
    scanf(" %d", &n);

    resposta_main = Pot(x, n);
    
    printf("%f^%d = %.1f\n", x, n, resposta_main);

    getchar();
    return(0);
}

float Pot( float x, int n)
{
    float resposta = pow(x, n);

    return(resposta);
}