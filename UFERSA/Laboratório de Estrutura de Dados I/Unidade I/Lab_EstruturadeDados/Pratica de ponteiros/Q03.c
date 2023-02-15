#include <stdio.h>

int main(void){
    
    //declarando as variáveis.
    int a, b, c, d;
    int *p1;

    //ponteiro p2 recebe o endereço de a.
    int *p2 = &a;

    //ponteiro p3 recebe o endereço de c.
    int *p3 = &c;

    //p1 receve o valor de p2.
    p1 = p2;

    //altero o valor de p2 = 10, assim a = 10.
    //Entretando o valor de p1 também será 10, pois um ponteiro que recebe um endereço de outra variável, ele continua acessando aquele endereço (recebendo as modificações)
    *p2 = 10;

    b = 20;

    //declarando o ponteiro para ponteiro pp.
    int **pp;

    //o ponteiro para ponteiro recebe o endereço de p1, assim pp = 10.
    pp = &p1;

    //p3 recebe o valor da variável pp, então p3 = 10.
    *p3 = **pp;

    //declarando um ponteiro p4 que recebe o endereço de d.
    int *p4 = &d;

    //p4 receve o valor da variável b, e o conteúdo de p1. E depois incremento p1.
    *p4 = b + (*p1)++;
    
    //Assim o valor de a=11, b=20, c=10, d=30. 
    printf("%d\t%d\t%d\t%d\n", a, b, c, d);

    return 0;
}