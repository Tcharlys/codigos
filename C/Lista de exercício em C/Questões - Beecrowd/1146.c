#include <stdio.h>

int main()
{
	int n, i;
	
	do
	{	
		scanf("%d", &n);
		
		for( i=1 ; i<=n ; i++)
		{
			printf(" %d", i);
		}
		
	puts("");
	
	}while(n!=0);
	
	return 0;	
}
