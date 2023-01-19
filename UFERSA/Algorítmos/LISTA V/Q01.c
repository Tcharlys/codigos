#include <stdio.h>

/* 1. O “Hello World” é a frase que todo programador apresenta como sinal de sucesso
do seu primeiro programa. Vamos manter a tradição, mas com uma execução
diferente. Crie um programa que apresente quatro vezes a frase “Hello, World!”,
cada qual de uma forma distinta, conforme a saída a seguir. 
Dica: use, dentro da função printf, os caracteres especiais \n para pular uma linha e
\t para tabular a informação no sentido horizontal.*/

int main()
{
    printf("Hello, World!\n\n");
    printf("Hello,\nWorld!\n\n");
    printf("\tHello, World!\n");
    printf("Hello,\n\tWorld!");
    
    return 0;
}