#include <stdio.h>
#include <stdlib.h>

float **criaMatrizFloat(int linhas, int colunas){
    float **matriz = (float**) malloc(linhas * sizeof(float *));

    int i;

    for ( i = 0; i < colunas; i++)
    {
        matriz[i] = (float*) malloc(colunas * sizeof(float));
    }
    
    return matriz;
}

int main(void){
    int linhas = 2;
    int colunas = 2;
    int i, j;

    float **matriz = criaMatrizFloat(linhas, colunas);
    
    printf("Digite os valores para a matriz.\n");
    
    for ( i = 0; i < linhas; i++)
    {
        for ( j = 0; j < colunas; j++)
        {
            scanf("%d ", &matriz[i][j]);
        }
    }
    
    for ( i = 0; i < colunas; i++)
    {
        free(matriz[i]);
    }
    
    free(matriz);

    return 0;
}