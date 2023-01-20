#include <stdio.h>
#include <stdlib.h>

int main()
{

    int a = 10, *x = 0;

    float b = 32, *y = 0;

    char c, *z = 0;

    x = &a;

    printf("Exibindo A antes da alteracao %d\tO ponteiro de A antes da alteracao -> %d\n\n", a, *x);

    a = 2 + *x;

    y = &b;

    printf("Exibindo B antes da alteracao %f\tO ponteiro de B antes da alteracao -> %f\n\n", b, *y);

    b = 1231 * (3.1220/ *y);

    z = &c;

    printf("Exibindo A %d\tO ponteiro de A -> %d\n", a, *x);

    printf("Exibindo B %f\tO ponteiro de B -> %f\n\n", b, *y);

    scanf("%c", &c);

    printf("Exibindo C %c\tO ponteiro de C %c", c, *z);

    return 0;
}