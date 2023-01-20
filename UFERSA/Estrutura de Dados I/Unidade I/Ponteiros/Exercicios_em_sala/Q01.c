#include <stdio.h>

int main()
{
    int x, *p;
    int y;

    y = 8;

    p = &y;

    x = *p;

    (*p)++;

    printf("Exibindo o conteudo de p\t%d\nExibindo o valor de X\t%d\n", *p, x);

    return 0;
}