#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale (LC_ALL, " ");

    int x=5, y=5, x1=5, y1=5;
    
    ++x;
    y--;
    
    x1++;
    --y1;

    printf("\n x=%d y=%d", x, y);
    
    printf("\n x=%d y=%d", x1, y1);

    return 0;
}