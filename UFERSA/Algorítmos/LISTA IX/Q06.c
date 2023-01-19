#include <stdio.h>
#include <locale.h>

/* 6. Faça um programa que solicita e armazena cinco números inteiros em um vetor,
denominado de v1. Construa outro vetor, denominado de v2, do mesmo tipo e
tamanho de v1, onde cada valor de v2 deve ser definido com o resultado do fatorial
de cada elemento correspondente em v1.
Ao final, o programa deve exibir o conteúdo dos vetores v1 e v2. */

int main()
{
    setlocale(LC_ALL, " ");

    int v1[5], v2[5], i, cont, fatorial=1;

    for ( i = 0; i < 5; i++)
    {
        scanf(" %d", &v1[i]);
        
        for ( cont = 1; cont <= v1[i]; cont++)
        {
            if (v1[i] >= 1)
            {
                fatorial*=cont;

                v2[i]=fatorial;
            }
            

        }
    }
    
    for ( i = 0; i < 5; i++)
    {
        printf("Vetor v1[%d]=%d\n", i, v1[i]);
        printf("Vetor v2[%d]=%d\n", i, v2[i]);
    }
    
    return(0);
}