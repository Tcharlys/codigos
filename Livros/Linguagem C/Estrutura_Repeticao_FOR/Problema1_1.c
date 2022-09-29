#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, " ");

    int n;

    for (n=0; n<20; n=n+2)
    {
        printf("%d\n", n);
    }
    return 0;
}