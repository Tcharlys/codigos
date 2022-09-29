#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, " ");

    float media, nota1, nota2, nota3;
    int opcao;

    do
    {
        printf("Digite a nota da 1ª AVALIAÇÃO\n");
        scanf("%d", &nota1);

        printf("Digite a nota da 2ª AVALIAÇÃO\n");
        scanf("%d", &nota2);

        printf("Digite a nota da 3ª AVALIAÇÃO\n");
        scanf("%d", &nota3);

        media=((nota1+nota2+nota3)/3);

        printf("Média=%.2f\n\n", media);

        printf("Digite:\n1->Para continuar\n0->Para Finalizar\n\n");
        scanf("%d", &opcao);

    } while (opcao!=0);
    
    return 0;
}