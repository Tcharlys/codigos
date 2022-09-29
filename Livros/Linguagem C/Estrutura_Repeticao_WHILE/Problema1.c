#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, " ");

    int n=0;

    while (n<=10)
    {
        printf("%d\n", n);

        n++;
    }
    
    return 0;
}