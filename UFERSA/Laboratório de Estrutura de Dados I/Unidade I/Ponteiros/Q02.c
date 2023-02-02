#include <stdio.h>

/* 2. Escreva um programa em C para demonstrar como lidar com os
ponteiros do programa.

Saída esperada:
    Endereço de m: 0x7ffcc3ad291c
    Valor de m : 29                                                                                              
                                                                                                              
    Agora ab é atribuído com o endereço de m.                                                                    
    Endereço do ponteiro ab: 0x7ffcc3ad291c                                                                       
    Conteúdo do ponteiro ab : 29                                                                                   
                                                                                                              
    O valor de m atribuído a 34 agora.                                                                           
    Endereço do ponteiro ab: 0x7ffcc3ad291c                                                                       
    Conteúdo do ponteiro ab : 34                                                                                   
                                                                                                              
    A variável de ponteiro ab é atribuída com o valor 7 agora.                                                    
    Endereço de m: 0x7ffcc3ad291c                                                                                
    Valor de m : 7
*/

int main(){
    int m = 29, *ab = &m;

    printf("Endereco de m = %p\n", &m);
    printf("Valor de m = %d\n", m);
    
    printf("Endereco do ponteiro ab = %p\n", &ab);
    printf("Conteudo do ponteiro ab = %d\n", *ab);

    m = 34;

    printf("Endereco de m = %p\n", &m);
    printf("Valor de m = %d\n", m);

    *ab = 7;

    printf("Endereco de m = %p\n", &m);
    printf("Valor de m = %d\n", m);
    
            
    return 0;
}