#include <stdio.h>

int main(){
    
    float x;

    scanf("%f", &x);
    if ((x>=0) && (x<=100))
    {
        if ((x>=0) && (x<=25))
        {
            printf("Intervalo [0,25]");
        }
        if ((x>25) && (x<=50))
        {
            printf("Intervalo (25,50]");
        }
        if ((x>50) && (x<=75))
        {
            printf("Intervalo (50,75]");
        }
        if ((x>75) && (x<=100))
        {
            printf("Intervalo (75,100]");
        }
    }
    else
    {
        printf("Fora do Intervalo");
    }
    
    return 0;
}