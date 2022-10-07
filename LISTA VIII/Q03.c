#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, " ");

    int n, cont=(-1), positivo=0, negativo=0;
    float media, soma, quant_negativo=0, quant_positivo=0;

    while (n!=0)
    {

        printf("Informe um número qualquer\n");
        scanf(" %d", &n);

        soma=soma+n;
        cont++;

        if (n>0)
        {
            positivo++;
        }
        
        if (n<0)
        {
            negativo++;
        }
    }
        
        media=(soma)/cont;
        quant_negativo=((float)negativo/(float)cont)*100;
        quant_positivo=((float)positivo/(float)cont)*100;
        

        printf("Média %.2f\n", media);
        printf("Núemros positivos %d\n", positivo);
        printf("Porcentagem de números positivos %.2f%%\n", quant_positivo);
        printf("Números negativos %d\n", negativo);
        printf("Porcentagem de números negativos %.2f%%", quant_negativo);
    
    return 0;
}