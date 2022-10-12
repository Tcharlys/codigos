#include <stdio.h>

int main()
{
    int n, n1, s;

    printf("Digite um número\n");
    scanf("%d", &n);

    printf("Digite outro número\n");
    scanf("%d", &n1);

    printf("%d + %d = %d\n\n", n, n1, s = n + n1);

    system("pause");
    return 0;
}
