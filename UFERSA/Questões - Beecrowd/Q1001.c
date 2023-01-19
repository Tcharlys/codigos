#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL,"");

        int A, B, X;

        printf("Digite dois números inteiros\n");
        scanf("%d %d", &A, &B);

        X=A+B;

        printf("X= %d\n", X);

    system("pause");
    return 0;
}