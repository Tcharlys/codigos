#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, " ");

    int n, d;

    printf("Digite o NUMERADOR e DENOMINADOR respectivamente\n");
    scanf("%d %d", &n, &d);

    if (n%d==0 && d!=0){
        printf("\nÉ divisível\n");
    }
    else{
        printf("\nNão é divisível\n");
    }
    if (d==0)
    {
        printf("\nDivisão indefinida\n");
    }

    return 0;
}