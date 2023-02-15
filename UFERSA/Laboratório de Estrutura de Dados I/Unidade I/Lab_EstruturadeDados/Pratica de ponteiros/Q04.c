#include <stdio.h>
#include <math.h>

//funcao que calcula o perimetro e a area do hexagono.
//recebe a variavel l, e os enderecos das variaveis area e perimetro da main como parametro.
void calcula_hexagono(float l, float *area, float *perimetro)
{   //formula do calculo do perimetro do hexagono.
    *perimetro = 6*l;

    //calculo da area do hexagono.
    *area = (3 * (pow(l, 2)) * sqrt(3))/2;

    //exibindo o perimetro e a area do hexagono.
    printf("Perimetro = %.2f\tArea = %.2f", *perimetro, *area);
}

int main()
{
    //declarando as variaveis
    float area,  perimetro, l;

    //solicitando a quantidade de lados de uma hexagono.
    printf("Digite a quantidade de lados o hexagono possui\n");
    scanf("%f", &l);
    
    //chamando a funcao calcula_hexagono.
    calcula_hexagono(l, &area, &perimetro);

    return 0;
}