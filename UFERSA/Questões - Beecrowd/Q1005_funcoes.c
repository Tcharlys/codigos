#include <stdio.h>

float media( float a, float b)
{
    float resultado_media=((a*3.5) + (b*7.5))/2;

    return(resultado_media);
}

int main()
{
    
    float a, b, resultado_main;

    printf("Informe dois números quaisquer\n");
    scanf(" %f %f", &a, &b);

    resultado_main=media(a, b);

    printf("MÉDIA = %f", resultado_main);

    return 0;
}