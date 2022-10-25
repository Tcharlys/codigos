#include <stdio.h>
#include <locale.h>

/* 8. (Prova EST/2010-2) Escreva um programa na linguagem C para receber um número N, inteiro, digitado
pelo usuário. Caso o número digitado seja ímpar e menor que 10, imprimir o fatorial desse número. O
cálculo do fatorial deve ser feito por uma função, que recebe o valor digitado por parâmetro e retorna
o valor do fatorial calculado. Caso N seja par e maior ou igual a dez, passar esse valor para outra
função por parâmetro e calcular e retornar a soma dos inteiros de 1 a N. Imprimir o valor retornado pela
função. */

int fatorial( int N);
int soma( int N);

int main()
{
    setlocale(LC_ALL, " ");

    int N, resposta_fatorial, resposta_soma;

    printf("Digite um número inteiro qualquer\n");
    scanf(" %d", &N);

    if ((N % 2 != 0) && (N < 10))
    {
        resposta_fatorial=fatorial(N);
    }
    
    if ((N % 2 == 0) && (N == 10))
    {
        resposta_soma=soma(N);
    }
    
    printf("%d! = %d\n", N, resposta_fatorial);
    printf("Soma de 1 - %d = %d\n", N, resposta_soma);

    getchar();
    return (0);
}

int fatorial( int N)
{
    int i, resposta=1;

    for ( i = 0; i <= N; i++)
    {
        resposta=N*resposta;
    }
    
    return(resposta);
}

int soma( int N)
{
    int i, resposta;

    for ( i = 0; i < N; i++)
    {
        resposta = i+resposta;
    }

    return(resposta);
}