#include <stdio.h>

int main()
{
	int c, i, j;
	float M[12][12], soma=0;
	char opcao[2];

	printf("Digite a coluna em que dejesa fazer a operação\n");
	
	do
	{
		printf("OBS: o valor da coluna deve está entre 0 12\n");
		scanf("%d", &c);
		
		if ((c < 0) || (c >= 12))
		{
			printf("Digite outro valor\n\n");
		}
		
	} while ((c < 0) || (c >= 12));
	
	printf("Informe a operação\nSoma -> S\tMédia -> M\n");
	scanf("%s", opcao);

	for ( i = 0; i < 12; i++)
	{
		for ( j = 0; j < 12; j++)
		{
			scanf("%f", &M[i][j]);

			if (j==c)
			{
				soma+=M[i][j];
			}	
		}
	}
	/*
	switch (opcao[0])
	{
		case 'S':
		case 's':

			printf("%.1f\n", soma);
	
		break;
		case 'M':
		case 'm':
			printf("%.1f\n", soma/12);
		
		break;
		default:
			break;
	}
	*/
	printf("Exibindo a matriz...\n");

	for ( i = 0; i < 12; i++)
	{
		for ( j = 0; j < 12; j++)
		{
			printf(" %.1f", M[i][j]);
		}
		printf("\n");
	}

	printf("Cálculo a ser feito na coluna %d\n", c+1);

	for ( i = 0; i < 12; i++)
	{
		for ( j = 0; j < 12; j++)
		{
			if (j==c)
			{
				printf(" %.1f\n", M[i][j]);
			}
			
		}
	}

	printf("Resultado:\n");

	if ((opcao[0] == 'S') || (opcao[0] == 's'))
	{
		printf("Soma -> %.1f\n", soma);
	}
	else if ((opcao[0] == 'M') || (opcao[0] == 'm'))
	{
		printf("Média -> %.1f\n", soma/12);
	}
	
	return 0;
}
