#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, " ");

    int i=0, m;

    while (i<=9)
    {
        printf("5*%d=%d\n", i, m=5*i);
        i++;
    }
    
    return 0;
}