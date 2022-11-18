#include <stdio.h>
#include <locale.h>

/* 3. Faça um programa que solicita e armazena cinco números inteiros em um vetor. Em
seguida, o programa deve percorrer o vetor e somar todos os seus valores. Ao final,
o programa deve exibir o resultado da soma. */

int main()
{
    setlocale(LC_ALL, " ");

    int v[5], i, soma=0;

    printf("Digite 5 números inteiros\n");

    for ( i = 0; i < 5; i++)
    {
        scanf(" %d", &v[i]);
        
        soma=v[i] + soma;
    }

    printf("Soma -> %d\n", soma);
    

    
    
    return(0);
}