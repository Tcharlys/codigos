#include <stdio.h>

int main()
{
    int x, *p;
    
    x = 100;
    p = x;

    printf("Valor de p = %p\tValor de *p = %d", p, *p);
}