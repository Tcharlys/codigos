#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale (LC_ALL, " ");
    
    int i;
    float nota1, nota2, nota3, media;

    for (i=0 ; i<10 ; i++)
    {
        printf("Digite a nota da 1ª AVALIAÇÃO\n");
        scanf("%f", &nota1);

        printf("Digite a nota da 2ª AVALIAÇÃO\n");
        scanf("%f", &nota2);

        printf("Digite a nota da 3ª AVALIAÇÃO\n");
        scanf("%f", &nota3);

        media=((nota1+nota2+nota3)/3);

        if (media>=9)
        {
            printf("Média -> %.1f\nConceito -> A\n", media);
        }
        if ((media>=7) && (media<9))
        {
            printf("Média -> %.1f\nConceito -> B\n", media);
        }
        if ((media>=6) && (media<7))
        {
            printf("Média -> %.1f\nConceito -> C\n", media);
        }
        if ((media>=4) && (media<6))
        {
            printf("Média -> %.1f\nConceito -> D\n", media);
        }
        if (media<4)
        {
            printf("Média -> %.1f\nConceito -> E\n", media);
        }
    }
    
    return 0;
}