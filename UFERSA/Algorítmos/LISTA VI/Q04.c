#include <stdio.h>
#include <locale.h>

int main ()
{
    setlocale(LC_ALL," ");
   
    int quantidade;
    float preco;

    printf("\t<<<PROMOÇÃO>>>\n1 DÚZIA de MAÇÃS -> R$1.10\nMENOS que UMA DÚZIA -> R$1.30\n");
    printf("Informe a quantidade que o(a) senhor(a) quer.\n");
    scanf("%d", &quantidade);

    if (quantidade>12){
        preco=quantidade*1.10;
        printf("TOTAL A PAGAR por %d MAÇÃS -> R$ %.2f", quantidade, preco);    
    }
    else{
        preco=quantidade*1.30;
        printf("TOTAL A PAGAR por %d MAÇÃS -> R$ %.2f", quantidade, preco);
    }
    
    return 0;
}