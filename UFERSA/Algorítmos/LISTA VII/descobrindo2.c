#include <stdio.h>
#include <locale.h>
#include <conio.h>

int main()
{
    setlocale (LC_ALL, " ");

    int lin, col, n;
    
    clrscr();
    printf("\n Qual o tamanho do tabuleiro? ");
    scanf("%d", &n);
    
    for(lin=1 ; lin<=n ; lin++)
    {
    printf("\n");
        
        for(col=1 ; col<=n ; col++)
        {
            if((lin+col)%2==0) textcolor(YELLOW);
            else textcolor(GREEN);

            cprintf("%c%c",219,219);
        }
    }
    getch();

    return 0;
}