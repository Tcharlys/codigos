#include <stdio.h>

void soma()
{
    int n1, n2, resultado;

    printf("Digite dois números\n");
    scanf("%d %d", &n1, &n2);

    printf("%d + %d = %d", n1, n2,resultado=n1+n2);

}

int main(){

    soma();
    
    return 0;
}