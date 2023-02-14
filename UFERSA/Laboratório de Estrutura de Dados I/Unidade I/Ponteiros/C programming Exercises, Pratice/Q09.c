#include <stdio.h>
#include <stdlib.h>

/*
9. Escreva um programa em C para encontrar o maior elemento
usando a alocação dinâmica de memória.

Dados de teste:
Insira o número total de elementos (1 a 100):5

Número 1:5
Número 2:7
Número 3:2
Número 4:9
Número 5:8

Saída esperada:

O maior elemento é: 9,00
*/

int main(void){

    int n, i;

    scanf("%d",&n);

    int vetor[n];

    int *p_vetor = (int*)malloc(n*sizeof(int));

    if (p_vetor == NULL)
    {
        printf("Error: Out of memory\n");
        exit(1);
    }
    
    for ( i = 0; i < n; i++)
    {
        scanf("%d",&vetor[i]);

        p_vetor[i] = vetor[i];
    }

    for ( i = 0; i < n; i++)
    {
        printf("\nNumero %d : %d", i+1, p_vetor[i]);
    }
    
    free(p_vetor);

    return 0;
}