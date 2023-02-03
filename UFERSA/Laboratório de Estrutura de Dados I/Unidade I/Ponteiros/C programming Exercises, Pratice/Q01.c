#include <stdio.h>

/* 1. Escreva um programa em C para mostrar a declaração básica do
ponteiro. 

Saída esperada:
    Aqui está m=10, n e o são duas variáveis ​​inteiras e *z é um número inteiro                                          
                                                                                                              
    z armazena o endereço de m = 0x7ffd40630d44                                                                  
                                                                                                              
    *z armazena o valor de m = 10                                                                                
                                                                                                              
    &m é o endereço de m = 0x7ffd40630d44                                                                      
                                                                                                              
    &n armazena o endereço de n = 0x7ffd40630d48                                                                  
                                                                                                              
    &o armazena o endereço de o = 0x7ffd40630d4c                                                                 
                                                                                                              
    &z armazena o endereço de z = 0x7ffd40630d50
*/

int main(){
    int m, n, e, o;
    int *z = &m;

    printf("z armazena o endereco de m = %p\n", z);
    printf("*z armazena o valor de m = %d\n", *z);
    printf("&m e o endereco de m = %p\n", &m);
    printf("&n armazena o endereco de n = %p\n", &n);
    printf("&o armazena o endereco de o = %p\n", &o);
    printf("&z armazena o endereco de z = %p\n", &z);
    
    return 0;
}