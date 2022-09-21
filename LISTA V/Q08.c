#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

/* 8. Implemente um programa que solicita ao usuário a sua idade e calcula quantos dias
de vida, aproximadamente, ele já viveu. Para simplificar o seu trabalho, ignore os
anos bissextos e use somente a idade, mas deixe o usuário ciente de que o resultado
apresentado é um valor aproximado. */

int main()
{
    setlocale(LC_ALL,"");

    int idade, dias;

    printf("\t<<<DIAS VIVIDOS>>>\nInforme sua idade\n");
    scanf("%d", &idade);

    //dias=idade*365;

    printf("\nAproximadamente foram %d dias que se passaram desde seu nacimento\n\n", idade=idade*365);

    system("pause");
    return 0;
}