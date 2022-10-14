#include <stdio.h>

float media( float a, float b, float c)
{
    float resultado_media=( ( (a*2.0) + (b*3.0) + (c*10.0) )/3 );

    return(resultado_media);
}

int main()
{

    float a, b, c, resultado_main;

    printf("Digite três notas\n");
    scanf(" %f %f %f", &a, &b, &c);

    resultado_main=media(a, b, c);

    printf("MÉDIA = %f", resultado_main);
    
    return 0;
}