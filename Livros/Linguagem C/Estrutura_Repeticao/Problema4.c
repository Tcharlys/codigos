#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, " ");

    int i=0, n;
    
    while (i<10)
    {
        n=0;

        while (n<9)
        {
            printf("\n%d*%d=%d\n", i, n, n*i);
            n++;
        }
        
        printf("%d*%d=%d\n", i, n, n*i);
        i++;
    }

    return 0;
}