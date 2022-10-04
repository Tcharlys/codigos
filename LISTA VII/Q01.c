#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale (LC_ALL, " ");

    int i;

    for (i=500 ; i>0 ; i--)
    {
        printf("\n%d", i);
    }    
    return 0;
}