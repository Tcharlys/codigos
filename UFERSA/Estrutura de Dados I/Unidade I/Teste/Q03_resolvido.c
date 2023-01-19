#include <stdio.h>

int main()
{
    int N_ant, N_prox, N, N_atual, i;
    N_ant = N_atual = 1;

    for ( i = 1; i <= N; i++)
    {
        N_prox = N_ant + N_atual;
        N_ant = N_atual;
        N_atual = N_prox;
    }
    
    printf("Fim do laco!\n");
    printf("N -> %d\nN_prox -> %d\nN_ant -> %d\nN_atual -> %d", N, N_prox, N_ant, N_atual);

    return 0;
    }