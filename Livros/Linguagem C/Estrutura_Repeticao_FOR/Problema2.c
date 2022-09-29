#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, " ");

    int n, num, soma, produto;

    puts("Informe um Nº");
    scanf("%d", &num);

    for (soma=0 , n=produto=1 ; n<=num ; n++)
    {
        soma=soma+n;
        produto=produto*n;
    }

    printf("Soma=%d\nProduto=%d\n\n", soma, produto);

    return 0;
}