#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, " ");

    int n;

    for (n=0; n<=20; n++)
    {
        if (n%2!=0)
        {
            printf("%d ", n);
        }
    }
    
    return 0;
}