#include <stdio.h>
#include <locale.h>

int main (){
    setlocale(LC_ALL," ");

    int opcao, quantidade;
    float preco;

    printf("------------------------------------------------------------\n");
    printf("|CÓDIGO DO ITEM         ESPECIFICAÇÃO            PREÇO     |\n");
    printf("|----------------------------------------------------------|\n");
    printf("|     100              Cachorro quente           R$8,00    |\n");
    printf("|     101                   Bauru                R$9,00    |\n");
    printf("|     102                  X-Salada              R$10,00   |\n");
    printf("|     103                 Hambúrguer             R$12,00   |\n");
    printf("|     104             Refrigerante (lata)        R$3,00    |\n");
    printf("------------------------------------------------------------\n");
    
    printf("Digite o cÓdigo do que o(a) senhor(a) deseja\n");
    scanf("%d", &opcao);
    printf("\nDigite a quantidade que o(a) senhro(a) deseja\n");
    scanf("%d", &quantidade);

    switch (opcao){
    case 100:
        preco=quantidade*8.00;
        printf("\nPedido -> Cachorro quente\nQuantidade -> %d\nTOTAL a pagar -> R$ %.2f", quantidade, preco);

        break;
    case 101:
        preco=quantidade*9.00;    
        printf("\nPedido -> Bauru\nQuantidade -> %d\nTOTAL a pagar -> R$ %.2f", quantidade, preco);
        
        break;
    case 102:
        preco=quantidade*10.00;
        printf("\nPedido -> X-Salada\nQuantidade -> %d\nTOTAL a pagar -> R$ %.2f", quantidade, preco);

        break;
    case 103:
        preco=quantidade*12.00;
        printf("\nPedido -> Hamburguer\nQuantidade -> %d\nTOTAL a pagar -> R$ %.2f", quantidade, preco);

        break;
    case 104:
        preco=quantidade*3.00;
        printf("\nPedido -> Refrigerante (lata)\nQuantidade -> %d\nTOTAL a pagar -> R$ %.2f", quantidade, preco);

        break;
    default:
        printf("\nOpção inválida\n");

        break;
    }
    
    return 0;
}