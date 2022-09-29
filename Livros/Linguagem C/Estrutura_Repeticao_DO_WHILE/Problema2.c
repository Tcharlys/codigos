#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, " ");

    char opcao;

do
{
    printf("\tClientes\n\tFornecedores\n\tEncomendas\n\tsair\n");
    scanf("%c", &opcao);

    switch (opcao)
    {
        case 'c':
        case 'C':

            printf("Opção clente\n\n");
            break;

        case 'f':
        case 'F':

            printf("Opção Fornecedor\n\n");
            break;
        case 'e':
        case 'E':

            printf("Opção Encomendas\n\n");
            break;
    
        case 's':
        case 'S':

        printf("Opção Sair\n\n");
            break;
        default:

        printf("//Opção Inválida\n\n");
            break;
    }

} while (opcao != 'S' && opcao != 's');

    

    return 0;
}