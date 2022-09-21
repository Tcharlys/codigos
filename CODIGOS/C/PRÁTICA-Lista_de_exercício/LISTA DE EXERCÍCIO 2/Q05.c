#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, " ");
    
    int X, Y, Z;

    printf("DESCOBRINDO O TRÃNGULO\n");
    printf("Digite os lados\n");
    scanf("%d %d %d", &X, &Y, &Z);
    
    if (X+Y>Z && X+Z>Y && Y+Z>X)
    {
        printf("\nOs lados informados forman um triângulo\n");
            if (X==Y && Y==Z && Z==X)
            {
                printf("\nTRIÂNGULO EQUILÁTERO\n");
                if (X==Y ||)
                {
                    printf("\nTRIÂNGULO ISÓSCELESn");
                }                
                else if (X!=Y && X!=Z && Y!=Z)
                {
                    printf("\nTRIÂNGULO ESCALENO\n")
                }
            
            }
            
    }
    
    return 0;
}