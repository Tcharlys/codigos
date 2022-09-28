#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, " ");

    int i=0, m, n;

    printf("Digite um número para saber a sua tabuada\n");
    scanf("%d", &n);
    printf("\n");
    
    while (i<=9)
    {
        printf("%d*%d=%d\n",n, i, m=n*i);
        i++;
    }

    return 0;
}