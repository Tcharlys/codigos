#include <stdio.h>
#include <stdlib.h>

typedef struct pessoa
{
    char nome[50];
    int num_documento;
    int idade;
}Pessoa;

void preenche_pessoa( int quant_pessoa, Pessoa *v_pessoa){
    int i;

    for ( i = 0; i < quant_pessoa; i++)
    {
        printf("\nDigite o nome da pessoa.\n");
        scanf(" %[^\n]s", v_pessoa[i].nome);

        printf("\nDigite o numero do documento.\n");
        scanf(" %d", &v_pessoa[i].num_documento);

        printf("\nDigite o idade da pessoa.\n");
        scanf(" %d", &v_pessoa[i].idade);
    }
}

void imprimi_pessoa( int quant_pessoa, Pessoa *v_pessoa){
    int i;
    
    for ( i = 0; i < quant_pessoa; i++)
    {
        printf("\n\n\tExibindo dados recebidos...\n");
        printf("Nome da pessoa.\t %s", v_pessoa[i].nome);

        printf("\nNumero de documento da pessoa\t %d", v_pessoa[i].num_documento);

        printf("\nIdade da pessoa\t %d", v_pessoa[i].idade);
    }
}

void altera_idade_pessoa( int quant_pessoa, Pessoa *v_pessoa){
    int i;

    for ( i = 0; i < quant_pessoa; i++)
    {
        printf("\n\n\tALterando a idade da pessoa...\n");
        scanf(" %d", &v_pessoa[i].idade);

        printf("\nIdade da pessoa atualizada:\n %d\n", v_pessoa[i].idade);
    }
}

void compara_idade_pessoa(int quant_pessoa, Pessoa *v_pessoa){
    int i;

    for ( i = 0; i < quant_pessoa; i++)
    {
        if ( v_pessoa[0].idade > v_pessoa[i].idade)
        {
            printf("\nNome da pessao mais velha. %s\n", v_pessoa[0].nome);
            printf("Idade da pessoa mais velha. %d\n", v_pessoa[0].idade);

            printf("\nNome da pessao mais nova. %s\n", v_pessoa[i].nome);
            printf("Idade da pessoa mais nova. %d\n", v_pessoa[i].idade);
        }
        else if ( v_pessoa[i].idade > v_pessoa[0].idade)
        {
            printf("\nNome da pessao mais velha. %s\n", v_pessoa[i].nome);
            printf("Idade da pessoa mais velha. %d\n", v_pessoa[i].idade);

            printf("\nNome da pessao mais nova. %s\n", v_pessoa[0].nome);
            printf("Idade da pessoa mais nova. %d\n", v_pessoa[0].idade);
        }
    }   
}

int main(void){

    int quant_pessoa;
        
    printf("Digite a quantidade de pessaos a serem cadastradas\n");
    scanf("%d",&quant_pessoa);
    
    Pessoa *v_pessoa = (Pessoa*) malloc(quant_pessoa * sizeof(Pessoa));

    if (v_pessoa == NULL)
    {
        printf("ERRO!\n");
        exit(1);
    }
    
    preenche_pessoa(quant_pessoa, v_pessoa);
    imprimi_pessoa(quant_pessoa, v_pessoa);
    altera_idade_pessoa(quant_pessoa,  v_pessoa);
    compara_idade_pessoa(quant_pessoa, v_pessoa);

    free(v_pessoa);
    
    return 0;
}    