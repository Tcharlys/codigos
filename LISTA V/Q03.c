#include <stdio.h>

/* 3. Todos os números naturais possuem antecessor, que é o número que antecede
(anterior) um valor específico, e sucessor, que é o número que sucede (posterior) um
valor específico. Sabendo disso, implemente um programa que solicita ao usuário a
entrada de um número inteiro e apresenta seu antecessor e sucessor. */

int main()
{
    int n, antecessor, sucessor;

        printf("<<ANTECESSOR E SUCESSOR>>\nDigite um número inteiro\n");
        scanf("%d", &n);

        /*antecessor=n-1;
        sucessor=n+1; */

        printf("ANTECESSOR<<-(%d):(%d):(%d)->>SUCESSOR\n\n", antecessor=n-1, n, sucessor=n+1);

    return 0;
}