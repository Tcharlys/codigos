#include <stdio.h>
#include <string.h>

/*
8. Escreva um programa em C para imprimir todas as pertumações de
uma determinada string usando ponteiros.

Saída esperada:

As permutações da string são:
abcd abdc acbd acdb adcb adbc bacd badc bcad bcda bdca bdac cbad cbda cabd cadb cdab cdba db
ca dbac dcba dcab dacb dabc
*/

void posicoes( char *ch1, char *ch2){
    char tmp;

    tmp = *ch1;
    *ch1 = *ch2;
    *ch2 = tmp;
}

void permutacoes(char *ch1, int stno, int endno){
    int i;

    if (stno == endno)
    {
        printf(" %s", ch1);
    }
    else
    {
        for ( i = stno; i <= endno; i++)
        {
            posicoes((ch1 + stno), (ch1 + i));
            permutacoes(ch1, stno + 1, endno);
            posicoes((ch1 + stno), (ch1 + i));
        }
    }
}

int main(void){
    char string[] = "abcd";

    printf("Permutaces de com ponteiros\n");

    int n = strlen(string);

    permutacoes( string, 0, n-1);

    printf("\n\n");

    return 0;
}