#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, " ");
	
	int n, cont, produto;
	
	scanf("%d", &n);
	
	for(cont=1 ; cont<=n ; cont++)
	{
		produto=cont*n;
		
		printf("%d * %d = %d\n", cont, n, produto);
	}
	return 0;	
}
