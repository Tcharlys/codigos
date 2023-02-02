#include <stdio.h>
#include <stdlib.h>

int main(void){
    
    int linhas = 3, coluna = 3, i, j;
    int **matrix = (int**) malloc(linhas * sizeof(int*));
    
    for (i = 0; i < linhas; i++){
        matrix[i] = (int *) malloc(coluna * sizeof(int));
    
        for (j = 0; j < coluna; j++){
            matrix[i][j] = i*3 +j;

            printf("Matrix[%d][%d] = %d\n", i, j, matrix[i][j]);
        }
    }
    
    for (i = 0; i < linhas; i++){
        free(matrix);
    }
    
    return 0;
}   