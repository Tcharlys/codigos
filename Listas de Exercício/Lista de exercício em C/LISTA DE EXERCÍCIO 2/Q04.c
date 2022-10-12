    #include <stdio.h>
    #include <locale.h>

    int main()
    {
        setlocale(LC_ALL, " ");

        int n;

        printf("Digite um número inteiro\n");
        scanf("%d", &n);

        if (n%2==0)
        {
            printf("\nO Nº é PAR\n");
        }
        else
        {
            printf("\nO Nº é ÍMPAR\n");   
        }
        
        return 0;
    }