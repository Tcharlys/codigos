#include <stdio.h>

int f(int mat[3][3])
{
    return (mat[0][0] * mat[1][1] * mat[2][2]) + (mat[0][1] * mat[1][2] * mat[2][0])
     + (mat[0][2] * mat[1][0] * mat[2][1]) - (mat[0][1] * mat[0][1] * mat[2][2]) 
     - (mat[0][0] * mat[1][2] * mat[2][1]) - (mat[0][2] * mat[1][1] * mat[2][0]);
}

int main()
{
    int m[3][3] = {{0, 1,0,}, {3, 1, -1}, {4, 0, 1}};
    
    int de = f(m);

    printf("Resultado = \t %d\n", de);

    return 0;
}