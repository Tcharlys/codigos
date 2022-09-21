#include <stdio.h>
#include <math.h>

int main()
{
    int A, B, C, maior_ab;

    scanf("%d %d %d", &A, &B, &C);

    maior_ab=(A+B+abs(A-B))/2;
    maior_ab=(C+maior_ab+abs(maior_ab-C))/2;

    printf("%d eh o maior", maior_ab);

    return 0;
}