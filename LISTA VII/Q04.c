#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale (LC_ALL, " ");
    
    int i, cont;

            if (i % 2==0)
            {
                printf("\nNúmeros difisíveis por 2 -> %d\nNúmeros -> %d", i, cont);
            }

    return 0;
}