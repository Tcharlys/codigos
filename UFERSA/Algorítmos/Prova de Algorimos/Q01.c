#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale (LC_ALL, " ");
    
    char opcao;
    int quantidade, forma_de_pagamento;
    float preco, desconto, preco_total;

    printf("|----------------------------------------------|\n");
    printf("|        !!!PROMOÇÃO IMPERDÍVEL!!!             |\n");
    printf("|----------------------------------------------|\n");
    printf("|                 Até 5Kg        Acima de 5Kg  |\n");
    printf("|File Duplo      R$ 4,90/Kg      R$ 5,80/Kg    |\n");
    printf("|Alcatra         R$ 5,90/Kg      R$ 6,80/Kg    |\n");
    printf("|Picanha         R$ 6,90/Kg      R$ 7,80/Kg    |\n");
    printf("|----------------------------------------------|\n");

    printf("O que o senhor gostaria de pedir?\n");
    printf("OBS: Use AS INICIAIS do tipo de carne\n");
    scanf(" %c", &opcao);

    printf("Qual a quantidade em (Kg) que o(a) senhor(a) deseja?\n");
    scanf(" %d", &quantidade);

    printf("CARTÃO TABAJARA +10%% de DESCONTO\n");
    printf("Informe a forma de pagamento\n");
    printf("1 -> Cartão Tabajara\n0 -> Dinheiro em espécie\n");
    scanf(" %d", &forma_de_pagamento);

    switch (opcao)
    {
    case 'F':
    case 'f':
        
        if (quantidade>5)
        {
            preco=(5.80*quantidade);
            
            if (forma_de_pagamento==1)
            {
                desconto=(preco*0.1);

                preco_total=preco-desconto;
            }

            else if (forma_de_pagamento==0)
            {
                desconto=preco*0;

                preco_total=preco;
            }
        }

        else if (quantidade<=5)
        {
            preco=(4.90*quantidade);

            if (forma_de_pagamento==1)
            {
                desconto=(preco*0.1);

                preco_total=preco-desconto;
            }

            else if (forma_de_pagamento==0)
            {
                desconto=preco*0;

                preco_total=preco;
            }
        }

        break;

    case 'A':
    case 'a':

        if (quantidade>5)
        {
            preco=(6.80*quantidade);
            
            if (forma_de_pagamento==1)
            {
                desconto=(preco*0.1);

                preco_total=preco-desconto;
            }
            
            else if (forma_de_pagamento==0)
            {
                desconto=preco*0;

                preco_total=preco;
            }
        }
        
        else if (quantidade<=5)
        {
            preco=(5.90*quantidade);

            if (forma_de_pagamento==1)
            {
                desconto=(preco*0.1);

                preco_total=preco-desconto;
            }

            else if (forma_de_pagamento==0)
            {
                desconto=preco*0;

                preco_total=preco;
            }
        }

        break;
    
    case 'P':
    case 'p':
    
        if (quantidade>5)
        {
            preco=(7.80*quantidade);
            
            if (forma_de_pagamento==1)
            {
                desconto=(preco*0.1);

                preco_total=preco-desconto;
            }

            else if (forma_de_pagamento==0)
            {
                desconto=preco*0;

                preco_total=preco;
            }
        }
            
        else if (quantidade<=5)
        {
            preco=(6.90*quantidade);

            if (forma_de_pagamento==1)
            {
                desconto=(preco*0.1);

                preco_total=preco-desconto;
            }

            else if (forma_de_pagamento==0)
            {
                desconto=preco*0;

                preco_total=preco;
            }
        }

        break;

    default:
        break;
    }

    printf(">>>CUPOM FISCAL<<<\n");

    if ((opcao=='F') || (opcao=='f'))
    {
        printf("Tipo da carne -> File Duplo\nQuantidade -> %d\nPreço Total -> R$%.2f\n", quantidade, preco);
        
        if(forma_de_pagamento==1)
        {
            printf("Forma de Pagamento -> Cartão Tabajara\n");
            printf("Desconto -> %.2f%%\n", desconto);
            printf("Valor a pagar -> R$ %.2f\n", preco_total);
        }

        else if (forma_de_pagamento==0)
        {
            printf("Forma de pagamento -> Dinheiro\n");
            printf("Desconto -> %.f\n", desconto);
            printf("Valor a pagar -> R$ %.2f\n", preco_total);
        }
    }
    
    if ((opcao=='A') || (opcao=='a'))
    {
        printf("Tipo da carne -> Alcatra\nQuantidade -> %d\nPreço Total -> R$%.2f\n", quantidade, preco);
        
        if(forma_de_pagamento==1)
        {
            printf("Forma de Pagamento -> Cartão Tabajara\n");
            printf("Desconto -> %.2f%%\n", desconto);
            printf("Valor a pagar -> R$ %.2f\n", preco_total);
        }

        else if (forma_de_pagamento==0)
        {
            printf("Forma de pagamento -> Dinheiro\n");
            printf("Desconto -> %.f\n", desconto);
            printf("Valor a pagar -> R$ %.2f\n", preco_total);
        }
    }

    if ((opcao=='P') || (opcao=='p'))
    {
        printf("Tipo da carne -> Picanha\nQuantidade -> %d\nPreço Total -> R$%.2f\n", quantidade, preco);
        
        if(forma_de_pagamento==1)
        {
            printf("Forma de Pagamento -> Cartão Tabajara\n");
            printf("Desconto -> %.2f%%\n", desconto);
            printf("Valor a pagar -> R$ %.2f\n", preco_total);
        }

        else if (forma_de_pagamento==0)
        {
            printf("Forma de pagamento -> Dinheiro\n");
            printf("Desconto -> %.f\n", desconto);
            printf("Valor a pagar -> R$ %.2f\n", preco_total);
        }
    }
            
    system("pause");
    return (0);
}