#include <stdio.h>
#include <locale.h>

/* Escreva um programa que realize a leitura dos salários pagos a um indivíduo durante um ano.
Em seguida, o programa deverá mostrar os valores mensais e o total anual. */

int main()
{
    setlocale(LC_ALL, " ");

    float salario_anual[13], total=0;
    int i, cont;
    
    for ( i = 1; i <= 12; i++)
    {
        printf("Digite o pagamento do mês (%d)\n", i);
        scanf(" %f", &salario_anual[i]);
    }
    
    for ( cont = 1; cont <= 12; cont++)
    {
        printf("Salário mês %d -> R$%f\n", cont, salario_anual[cont]);

        total+=salario_anual[cont];
    }
    
    printf("\nTotal anual -> R$%.2f\n", total);

    getchar();
    return (0);
}