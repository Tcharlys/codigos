#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int *vetor = (int*) malloc(10 * sizeof(int));
    int i;

    if (vetor == NULL){
        printf("Erro. Sem memoria para alocar\n");
    }
    
    for ( i = 0; i < 10; i++){
        vetor[i] = i;
        printf("Vetor[%d] = %d\n", i, vetor[i]);
    }
    
    free(vetor);

    return 0;
}