#include<stdio.h>
#include<locale.h>

/* 2. Fazer um programa em C que imprime uma tabela com a tabuada de 1 a 9 */

void main()
{
setlocale(LC_ALL,"");

int n, i, tabuada;
printf("<---TABUADA DE 1 A 9--->\n");

for(n=0; n<=9; n++){
    for(i=0; i<=9; i++){
        tabuada = n*i;

        printf("%d*%d=%d\t", n, i, tabuada);
    }
}

    printf("\n\n");

    system("pause");
    return 0;
}