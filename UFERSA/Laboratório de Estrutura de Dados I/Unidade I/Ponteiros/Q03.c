#include <stdio.h>

/* 3. Escreva um programa em C para demonstrar o uso dos operadores
&(endereço de) e *(valor no endereço).

Saída esperada:

Ponteiro: Demonstra o uso de & e operador *:                                                          
-------------------------------------------------- ------                                                      
    m = 300                                                                                                      
    fx = 300.600006                                                                                              
    cht = z                                                                                                      
                                                                                                              
Usando & operador:                                                                                           
------------------------                                                                                       
    endereço de m = 0x7ffda2eeeec8                                                                                
    endereço de fx = 0x7ffda2eeeecc                                                                               
    endereço de cht = 0x7ffda2eeeec7                                                                              
                                                                                                              
Usando o operador & e *:                                                                                     
------------------------                                                                                 
    valor no endereço de m = 300                                                                                  
    valor no endereço de fx = 300.600006                                                                          
    valor no endereço de cht = z                      

Usando apenas a variável de ponteiro:                                                                                
----------------------------------                                                                            
    endereço de m = 0x7ffda2eeeec8                                                                                
    endereço de fx = 0x7ffda2eeeecc                                                                               
    endereço de cht = 0x7ffda2eeeec7                                                                              
                                                                                                              
Usando apenas o operador de ponteiro:                                                                                
----------------------------------                                                                            
    valor no endereço de m = 300                                                                                  
    valor no endereço de fx= 300.600006                                                                           
    valor no endereço de cht= z
*/
int main(){
    
    int m, *p_m = &m;
    float fx, *p_fx = &fx;
    char cht, *p_cht = &cht;

    *p_m = 300;
    *p_fx = 300.600006;
    *p_cht = 'z';

    printf("Ponteiro: Demonstra o uso de & e operador *\n:");
    printf("--------------------------------------------------------\n");
    printf("m = %d\n", m);
    printf("")
    return 0;
}