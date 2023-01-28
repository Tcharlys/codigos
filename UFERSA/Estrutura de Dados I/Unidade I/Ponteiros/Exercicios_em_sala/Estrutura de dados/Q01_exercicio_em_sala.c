include <stdio.h>

void incrementa(int *numero)
{
    (*numero)++;
}
int main()
{
    int numero = 5;

    incrementa(&numero);

    printf("%d\n", numero);
    
    return 0;
}