#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, " ");

    int i, n, produto;

    for (i=0 ; i<=5 ; i++)
    {
        for (n=0 ; n<10 ; n++)
        {
            printf("%d*%d=%d\n", i, n, produto=i*n);
        }
        
        printf("%d*%d=%d\n", i, n, produto=i*n);

        if (i!=5)
        {
            printf("\nPrecione <<<ENTER>>> para continuar\n\n");
            getchar();
        }
    }
    
    return 0;
}