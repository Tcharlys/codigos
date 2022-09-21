#include<stdio.h>
#include<ctype.h>
int main(){
	int i,j,x,y;
	char ch='*';
	printf("Programa que imprime um quadrado em forma de *\n");
	printf("De o numero de linhas do quadrado\n");
	scanf("%i", &x);
	printf("De o numero de colunas do quadrado\n");
	scanf("%i", &y);
    
		for(i=0;i<x;i++)
		{
		for(j=1;j<=y;j++)
		{
			printf("%c", ch);
		}
			printf("\n");
		}
		}