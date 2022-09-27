#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale (LC_ALL, " ");

    int i;

    for (i = 0; i <= 500; i++)
    {
        printf("\n%d", i);
    }    
    return 0;
}