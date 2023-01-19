#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale (LC_ALL, " ");

    int somatorio, i;

    for (i=1 ; i<=500 ; i++)
    {
        
        if (i%2==0)
        {
        somatorio=somatorio+i;

        printf("Índice -> %d\nSomatório -> %d\n\n", i, somatorio);
        
        }
    }
    
    return 0;
}