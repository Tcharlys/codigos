#include <stdio.h>
#include <locale.h>

int main ()
{
    setlocale(LC_ALL," ");

    int n;

    printf("Informe mum número inteiro\n");
    scanf("%d", &n);

    if (n>0){
        printf("\nO núemro digitado é POSITIVO\n");
    }
    if (n<0){
        printf("\nO número digitado é NEGATIVO\n");
    }
    if (n==0){
        printf("\nO número digitado é NEUTRO\n");
    }
    
    return 0;
}