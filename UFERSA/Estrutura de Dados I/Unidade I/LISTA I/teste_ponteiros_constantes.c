#include <stdio.h>

int main()
{
    int a = 16, b = 20;
    int *const p = &a;

    printf("Ponteiro P apontando para A %d", *p);
    //printf("Ponteiro P apontando para A (Endereco) %d\n\n", p);


    p = &b;

    printf("Ponteiro P apontando para B %d", *p);
    //printf("Ponteiro P apontando para B (Endereco) %d", p);



    return 0;
}