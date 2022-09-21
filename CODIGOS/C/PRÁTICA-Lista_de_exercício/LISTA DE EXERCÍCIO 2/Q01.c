    #include <stdio.h>

    int main()
    {
        int h, m, s;
        printf("Informe um tempo em Segundos(s) de um evento\n");
        scanf("%d", &s);

        printf("\nValor correspondente em:\nHoras -> %d\nMinutos -> %d\nsegundos -> %d\n\n", h=s/3600, m=s/60, s);
        
        return 0;
    }