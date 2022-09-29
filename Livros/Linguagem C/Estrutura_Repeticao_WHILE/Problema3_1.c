#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, " ");

    int i=0, m;
    
    while (i<=10)
    {
        printf("%d*%d=%d\n",5, i, m=5*i);
        i++;
    }

    return 0;
}