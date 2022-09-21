#include <stdio.h>
#include <locale.h>

int main ()
{
    setlocale(LC_ALL," ");

    int opcao;
    float n1, n2, soma, subtracao, multiplicacao, divisao;

    printf(">>>CALCULADORA BASICA<<<\n");
    printf("1->SOMA\n2->SUBTRAÇÃO\n3->MULTIPLICAÇÃO\n4->DIVISÃO\n");
    scanf("%d", &opcao);

    printf("\nInforme dois números\n");
    scanf("%f %f", &n1, &n2);

    switch (opcao){
    case 1:
        printf("\n%.2f+%.2f=%.2f\n", n1, n2, soma=n1+n2);
        break;
    case 2:
        printf("\n%.2f-%.2f=%.2f\n", n1, n2, subtracao=n1-n2);
        break;
    case 3:
        printf("\n%.2fx%.2f=%.2f\n", n1, n2, multiplicacao=n1*n2);
        break;
    case 4:
        if (n2!=0){
            printf("\n%.2f/%.2f=%.2f\n", n1, n2, divisao=n1/n2);
        }
        else{
            printf("\nA divisão é indefinida\n");
        }
    default:
        printf("\nOpção inválida. tente outra vez.\n");
    }
    return 0;
}