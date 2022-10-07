#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, " ");
	
	int menor, maior=0, cont=0, posicao;
	
	for(cont=1 ; cont<=10 ; cont++)
	{
		printf("Digite um número inteiro positivo");
		scanf(" %d", &menor);
		
		if(maior < menor)
		{
			maior=menor;
			posicao=cont;
		}
	}
	
	printf("Maior Nº %d\nNa posicao %d", maior, cont);
		
	return 0;
}
