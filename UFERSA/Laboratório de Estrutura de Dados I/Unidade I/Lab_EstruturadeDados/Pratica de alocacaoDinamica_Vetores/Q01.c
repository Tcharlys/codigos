#include <stdio.h>
#include <stdlib.h>

int main(void){
    
    int Qtdpessoas, i, Qtd_feminino = 0, Qtd_masculino = 0;

    printf("Digite o numeros de pessoas que serao entrevistadas\n");
    scanf("%d", &Qtdpessoas);

    char *sex_entrevistado = (char *) malloc(Qtdpessoas*sizeof(char));
    if (sex_entrevistado == NULL)
    {
        printf("Memoria insuficiente\n");
        exit(1);
    }
    
    int *opi_produto = (int *) malloc(Qtdpessoas*sizeof(int));
    if (opi_produto == NULL)
    {
        printf("Memoria insuficiente\n");
        exit(1);
    }

    for (i = 0; i < Qtdpessoas; i++)
    {
        printf("Sexo do entrevistado:\n F. para feminino\n M. para masculino\n");
        scanf(" %c", &sex_entrevistado[i]);

        printf("Opiniao sobre o o Produto:\n 0. nao gostou\n 1.gostou\n");
        scanf(" %d", &opi_produto[i]);
    }
    
    for (i = 0; i < Qtdpessoas; i++)
    {
        if((sex_entrevistado[i] == 'F') || (sex_entrevistado[i] == 'f') && (opi_produto[i] == 1))
        {
            Qtd_feminino++;
        }

        if ((sex_entrevistado[i] == 'M') || (sex_entrevistado[i] == 'm') && (opi_produto[i] == 1))
        {
            Qtd_masculino++;
        }
    }
    
    Qtd_feminino = ((Qtd_feminino*100.0f) / Qtdpessoas);
    Qtd_masculino = ((Qtd_masculino*100.0f) / Qtdpessoas);
    
    printf("\nMulheres que gostaram do produto: %d %%\nHomens que gostaram do produto: %d %%\n", Qtd_feminino, Qtd_masculino);

    free(sex_entrevistado);
    free(opi_produto);

    return 0;
}