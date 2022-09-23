#include <stdio.h>

int main(){
    int opcao, quantidade;
    float preco;

    printf("------------------------------------------------------------\n");
    printf("|CÓDIGO DO ITEM         ESPECIFICAÇÃO            PREÇO     |\n");
    printf("|----------------------------------------------------------|\n");
    printf("|     1                Cachorro quente           R$4,00    |\n");
    printf("|     2                   X-Salada               R$4,50    |\n");
    printf("|     3                   X-Bacon                R$5,00    |\n");
    printf("|     4                   Torrada                R$2,00    |\n");
    printf("|     5                 Refrigerante             R$1,50    |\n");
    printf("------------------------------------------------------------\n");
    
    scanf("%d", &opcao);
    scanf("%d", &quantidade);
    
    switch (opcao)
    {
    case 1:
        preco=quantidade*4;

        printf("\nTotal: R$ %.2f\n", preco);
        break;
    case 2:
        preco=quantidade*4.50;
    
        printf("\nTotal: R$ %.2f\n", preco);
        break;
    case 3:
        preco=quantidade*5;

        printf("\nTotal: R$ %.2f\n", preco);
        
        break;
    case 4:
        preco=quantidade*2;

        printf("\nTotal: R$ %.2f\n", preco);
        
        break;
    case 5:
        preco=quantidade*1.50;

        printf("\nTotal: R$ %.2f\n", preco);
        
        break;
    default:
        printf("\nOPÇÂO INVÀLIDA\n");
        break;
    }

    return 0;
}