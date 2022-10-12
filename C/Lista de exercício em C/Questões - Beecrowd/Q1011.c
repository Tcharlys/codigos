#include <stdio.h>
#include <math.h>

int main()
{
    float raio, volume;
    
    scanf("%f", &raio);

    volume=(4/3)*3.14159*pow(raio, 3);

    printf("VOLUME = %.3f", volume);
    
    return 0;
}