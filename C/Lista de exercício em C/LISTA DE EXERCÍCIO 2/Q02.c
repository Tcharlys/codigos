    #include <stdio.h>

    int main()
    {
        int n1, n2, n3;
        float media;

        printf("Digite 3 notas\n");
        scanf("%d %d %d", &n1, &n2, &n3);

        printf("\nMédia=%.2f\n", media=(n1+n2+n3)/3);
        
        return 0;
    }