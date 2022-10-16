#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* 2. Escreva uma função que calcule e retorne a distância entre dois pontos 
(x1, y1) e (x2, y2). Todos os números e valores de retorno devem ser do
tipo float. */

float distancia(float x1, float y1, float x2, float y2)
{
    float distancia
}

int main()
{
    setlocale(LC_ALL, " ");

    float x1, x2, y1, y2;

    printf("Digite as coordenadas do primeiro ponto: x1 e y1\n");
    scanf(" %f %f", &x1, &y1);

    printf("Digite as coordenadas do segundo ponto: x2 e y2\n");
    scanf(" %f %f", &x2, &y2);
    
    distancia(x1, y1, x2, y2);

    system("pause");
    return(0);
}