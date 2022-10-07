#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, " ");

    int i;

    for (i=1 ; i<=100; i++)
    {
        printf("%d\n", i);
    }
        
    return 0;
}