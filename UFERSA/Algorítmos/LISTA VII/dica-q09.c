#include <stdio.h>
#include <locale.h>

int main ()
{

    setlocale(LC_ALL, " ");

    int x, y, cont1, cont2, div=0;
  
    printf("Informe um intervalo\n");
    scanf(" %d %d", &x, &y);

    for( cont2=x ; cont2<=y ; cont2++, div = 0)
    {   
        for(cont1=1; cont1<=cont2; cont1++)
        {  
        if (cont2%cont1==0)
        {
	        div++;
        }
        }
    
    //Só é primo se existir 2 ou mais divisores
        if(div==2)
        printf (" %i é primo\n",cont2);
        /*else
        printf ("%i não é primo\n",cont2);*/
    }

  return 0;
}