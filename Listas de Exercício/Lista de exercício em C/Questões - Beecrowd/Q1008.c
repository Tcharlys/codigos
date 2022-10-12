#include <stdio.h>

int main()
{
    int nfuncionario, htrabalhadas;
    float vphtrabalhadas, salario;

    printf("Digite seu número\n");
    scanf("%d", &nfuncionario);

    printf("Informe as horas trabalhadas\n");
    scanf("%d", &htrabalhadas);

    printf("Informe o valor (R$) que o senhor(a) ganha por hora\n");
    scanf("%f", &vphtrabalhadas);

    salario=htrabalhadas*vphtrabalhadas;

    printf("\nNÚMERO = %d\nSALÁRIO = %.2f", nfuncionario, salario);

    return 0;
}