#include <stdio.h>
#include <math.h>

void calcula_hexagono(float l, float *area, float *perimetro)
{
    *perimetro = 6*l;
    *area = (3 * (pow(l, 2)) * sqrt(3))/2;

    printf("Perimetro = %.2f\tArea = %.2f", *perimetro, *area);
}

int main()
{
    float area,  perimetro, l = 10;

    calcula_hexagono(l, &area, &perimetro);

    return 0;
}