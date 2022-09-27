#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale (LC_ALL, " ");

    int somatorio, i;

    for (i = 0; i <= 500; i++)
    {
        somatorio=somatorio+i;

        printf("Índice -> %d\nSomatório -> %d\n\n", i, somatorio);
    }
    
    return 0;
}