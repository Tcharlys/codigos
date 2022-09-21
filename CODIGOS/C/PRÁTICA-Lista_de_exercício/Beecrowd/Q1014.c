#include <stdio.h>

int main()
{
    float X, Y, consumomedio;

    scanf("%f %f", &X, &Y);

    printf("%.3f Km/l", consumomedio=(X/Y));

    return 0;
}