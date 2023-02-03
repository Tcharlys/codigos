#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    int qnd_frutas, linha;

    printf("Digiter a quantidade de frutas\n");
    scanf("%d", &qnd_frutas);

    char **frutas = (char**) malloc(qnd_frutas * sizeof(char*));

    if (frutas == NULL)
    {
        printf("Erro de memoria!\n");
        
        exit(1);
    }

    for ( linha = 0; linha < qnd_frutas; linha++)
    {
        frutas[linha] = (char*) malloc(50 * sizeof(char));

    }
    
    float *precos = (float*) malloc(qnd_frutas * sizeof(float));

    if (precos == NULL)
    {
        printf("Erro de memoria!\n");
        
        exit(1);
    }
    
    printf("Informe o nome da frutas e o seu valor\n");

    for ( linha = 0; linha < qnd_frutas; linha++)
    {
        scanf(" %[^\n]s", frutas[linha]);
        scanf("%f", &precos[linha]);

    }
    
    frutas = (char *) realloc(frutas, (strlen(frutas) + 1) * sizeof(char));
    
    for ( linha = 0; linha < qnd_frutas; linha++)
    {
        free(frutas[linha]);
    }
    
    free(precos);

    free(frutas);
    
    return 0;
}