#include <stdio.h>
#include <locale.h>

/* 2. Modifique o programa anterior para mostrar quatro frases diferentes, escolhidas por
você. Mantenha a forma de apresentação. */

int main()
{
    setlocale(LC_ALL,"");

    printf("Olá, finalmente tamo programando em C\n\n");
    printf("Não tava mais aguentando o VisualG\nFique tranquilo, vai dar tudo errado\n\n");
    printf("\tDigitando uma coisa aqui, sem ideia\n");
    printf("ùltima frase.\n\tnão tenho criatividade... Desculpe");

    return 0;
}