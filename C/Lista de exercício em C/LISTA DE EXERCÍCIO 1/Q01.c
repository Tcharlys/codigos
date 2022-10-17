#include <stdio.h>
#include <locale.h>

/* 1. Fazer um programa em C que pergunta um valor em metros e imprime o
correspondente em decímetros, centímetros e milímetros. */

void main()
{

setlocale(LC_ALL," ");

float metros;
float decimetros;
float centimetros;
float milimetros;

    printf(">>>CONVERSOR DE METROS<<<\nMETROS -> DECÍMETROS\nMETROS -> CENTÍMETROS\nMETROS -> MILÍMETROS");
    printf("Informe um valor em metros\n\n");
    scanf("%f", &metros);

    decimetros = metros * 10;
    centimetros = metros * 100;
    milimetros = metros * 1000;

    printf("%fm -> %fdcm\n\n", metros, decimetros);
    printf("%fm -> %fcm\n\n", metros, centimetros);
    printf("%fm -> %fmm\n\n", metros, milimetros);

    system("pause");
    return 0;
}