#include <stdio.h>

void invert( int vet[], int n)
{
    int vet_aux[n];
    int i;

    for (i = 0; i < n; i++)
    {
        vet_aux[i] = vet[i];
    }
    
    for ( i = 0; i < n; i++)
    {
        vet[i] = vet_aux[n-1-i];
    }

}

int main()
{
    int vet[5] = {1, 2, 3, 4, 5}, cont;
    
    invert(vet, 5);

    for ( cont = 0; cont < 5; cont++)
    {
        printf("%d\t", vet[cont]);
    }

    return 0;
}