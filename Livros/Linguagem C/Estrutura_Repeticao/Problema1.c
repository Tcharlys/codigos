#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, " ");

    int i=0;

    while (i<=10)
    {
        printf("%d\n", i);

        i++;
    }
    
    return 0;
}