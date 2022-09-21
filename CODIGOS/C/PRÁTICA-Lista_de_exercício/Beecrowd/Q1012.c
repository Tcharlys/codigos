#include <stdio.h>
#include <math.h>

int main()
{
    float A, B, C, areatrianguloretangulo, areacirculo, areatrapezio, areaquadrado, arearetangulo;

    scanf("%f %f %f", &A, &B, &C);

    areatrianguloretangulo=(A*C)/2;
    areacirculo=pow(C, 2)*3.14159;
    areatrapezio=((A+B)*C)/2;
    areaquadrado=pow(B, 2);
    arearetangulo=A*B;

    printf("TRIANGULO: %.3f\n", areatrianguloretangulo);
    printf("CIRCULO: %.3f\n", areacirculo);
    printf("TRAPEZIO: %.3f\n", areatrapezio);
    printf("QUADRADO: %.3f\n", areaquadrado);
    printf("RETANGULO: %.3f\n", arearetangulo);
    
    return 0;
}