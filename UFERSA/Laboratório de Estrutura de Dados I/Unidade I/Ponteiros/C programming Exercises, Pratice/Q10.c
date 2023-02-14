#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
10. Escreva um programa em C para calcular o comprimento da string
usando um ponteiro.

Dados de teste:
Insira um astring: w3resource

Saída esperada:
O comprimento da string fornecida w3resource
é: 10
*/

calcula_string(char *string){
    int ctr = 0;

    while (*string != '\0')
    {
        ctr++;
        string++;
    }
    
    return ctr;
}

int main(){

    char string[100];
    int p_string;

    printf("Digite alguma coisa\n");
    fgets(string, sizeof string, stdin);

    p_string = calcula_string(string);

    printf("O tamanho da string %s eh %d\n", string, p_string-1);

    return 0;
}