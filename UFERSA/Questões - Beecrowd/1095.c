#include <stdio.h>

int main()
{
	int i=1, j;
	
	for(j=60 ; j>=1 ; j--)
	{	
		printf("I=%d J=%d\n", i, j);
		
		i=i+3;
	}	
	
	return 0;	
}
