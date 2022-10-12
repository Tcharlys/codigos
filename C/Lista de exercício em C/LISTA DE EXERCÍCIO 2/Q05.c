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
            if (X==Y && Y==Z && Z==X)
            {
                printf("\nos lados forman um TRIÂNGULO EQUILÁTERO\n");
                if (X==Y || X==Z)
                {
                    printf("\nos lados forman um TRIÂNGULO ISÓSCELESn");
                }                
                else if (X!=Y && X!=Z && Y!=Z)
                {
                    printf("\nos lados forman um TRIÂNGULO ESCALENO\n");
                }
            }
    }
    
    return 0;
}