#include <stdio.h>

int (*operacao)(int, int);

int soma(int a, int b)
{
    return a + b;
}

int multiplica(int num1, int num2)
{
    return num1 * num2;
}

int calcula(int x, int y, int (*operacao)(int, int))
{
    return (*operacao)(x,y);
}

int main()
{
    int a = 2, b = 3;

    int resultado = calcula(a, b, multiplica);

    printf("%d\n", resultado);

    return 0;
}