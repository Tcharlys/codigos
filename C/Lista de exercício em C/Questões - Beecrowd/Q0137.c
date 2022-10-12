#include <stdio.h>

int main(){
    
    float x;

    scanf("%f", &x);
    if ((x>=0) && (x<=100))
    {
        if ((x>=0) && (x<=25))
        {
            printf("\nIntervalo [0,25]\n");
        }
        if ((x>25) && (x<=50))
        {
            printf("\nIntervalo (25,50]\n");
        }
        if ((x>50) && (x<=75))
        {
            printf("\nIntervalo (50,75]\n");
        }
        if ((x>75) && (x<=100))
        {
            printf("\nIntervalo (75,100]\n");
        }
    }
    else
    {
        printf("\nFora do Intervalo\n");
    }
    
    return 0;
}