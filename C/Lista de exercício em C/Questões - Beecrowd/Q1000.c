#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL,"");

    printf("Hello World!");
    
    system("pause");
    return 0;
}