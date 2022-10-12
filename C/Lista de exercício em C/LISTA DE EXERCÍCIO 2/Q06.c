#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, " ");

    float n1, n2, n3;

    printf("Digite três números quaisquer\n");
    scanf("%f %f %f", &n1, &n2, &n3);

    if (n1>n2)
    {
        printf("O maior ->%.1f", n1);
            if (n1>n3)
            {
                printf("O maior ->%.1f", n1);
            }
            else
            {
                printf("O maior ->%.1f", n3);
            }
    }
    else
    {
        printf("O maior ->%.1f", n2);
    }
    if (/* condition */)
    {
        /* code */
    }
    
        
    return 0;
}