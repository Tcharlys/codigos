#include <stdio.h>
#include <stdlib.h>

typedef struct funcionario{
    char nome[50];
    float salario;
    int identificador;
    char cargo[20];
}Funcionario;

void preenche(int quant_funcionario, Funcionario *v_funcionario){
    int i;

    for ( i = 0; i < quant_funcionario; i++)
    {
        printf("\nDigite o nome do funcionario %d\n", i+1);
        scanf(" %[^\n]s", v_funcionario[i].nome);

        printf("\nDigite o salario do funcionario\n");
        scanf(" %f", &v_funcionario[i].salario);

        printf("\nDigite o identificador do funcionario\n");
        scanf(" %d", &v_funcionario[i].identificador);

        printf("\nDigite o cargo do funcionario\n");
        scanf(" %[^\n]s", v_funcionario[i].cargo);
    }
}

void imprimi(int quant_funcionario, Funcionario *v_funcionario){
    int j; 

    for ( j = 0; j < quant_funcionario; j++)
    {
        printf("\n\tExibindo dados recebidos...\n");
        printf("\nNome do funcionario\t%s\n", v_funcionario[j].nome);
    
        printf("Salario do funcionario\t%f\n", v_funcionario[j].salario);

        printf("Identificador do funcionario\t%d\n", v_funcionario[j].identificador);

        printf("Cargo do funcionario\t%s\n", v_funcionario[j].cargo);  
    }
}

void altera_salario(int quant_funcionario, Funcionario *v_funcionario){
    int index;
    
    for ( index = 0; index < quant_funcionario; index++)
    {
        printf("\nDigite o reajuste do salario do funcionario %d\n", index+1);
        scanf(" %f", &v_funcionario[index].salario);
    }
}

void salario_maior(int quant_funcionario, Funcionario *v_funcionario){
    int i;

    for ( i = 0; i < quant_funcionario; i++)
    {
        if ( v_funcionario[0].salario > v_funcionario[i].salario)
        {
            printf("\nCargo do funcionario:\t%s\n", v_funcionario[0].cargo);
            printf("Maior salario do funcionario:\t%f\n", v_funcionario[0].salario);

            printf("\nCargo do funcionario:\t%s\n", v_funcionario[i].cargo);
            printf("Menor salario do funcionario:\t%f\n", v_funcionario[i].salario);
            
        }
        else if ( v_funcionario[0].salario < v_funcionario[i].salario)
        {
            printf("\nCargo do funcionario:\t%s\n", v_funcionario[i].cargo);
            printf("Maior salario do funcionario:\t%f\n", v_funcionario[i].salario);

            printf("\nCargo do funcionario:\t%s\n", v_funcionario[0].cargo);
            printf("Menor salario do funcionario:\t%f\n", v_funcionario[0].salario);
        }
    }
    
}

int main(void){

    int quant_funcionario;

    printf("Digite a quantidade de funcionarios suas empresa possui\n");
    scanf(" %d", &quant_funcionario);

    Funcionario *v_funcionario = (Funcionario*) malloc(quant_funcionario * sizeof(Funcionario));
    if (v_funcionario == NULL)
    {
        printf("ERRO!");
        exit(1);
    } 

    preenche(quant_funcionario, v_funcionario);
    imprimi(quant_funcionario, v_funcionario);
    altera_salario(quant_funcionario, v_funcionario);
    salario_maior(quant_funcionario, v_funcionario);

    free(v_funcionario);
    
    return 0;
}