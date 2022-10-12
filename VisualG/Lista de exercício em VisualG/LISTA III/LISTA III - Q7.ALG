Algoritmo "LISTA III - Q7"
Var

item: inteiro
quantidade: inteiro
preco: real

Inicio
      escreval("------------------------------------------------------------")
      escreval("|CÓDIGO DO ITEM         ESPECIFICAÇÃO       PREÇO UNITÁRIO |")
      escreval("|----------------------------------------------------------|")
      escreval("|     100              Cachorro quente           R$7,00    |")
      escreval("|     101                   Bauru                R$8,00    |")
      escreval("|     102                  X-Salada              R$9,00    |")
      escreval("|     103                 Hambúrguer             R$10,00   |")
      escreval("|     104             Refrigerante (lata)        R$3,00    |")
      escreval("------------------------------------------------------------")
      
      escreval("Qual Item o senhor(a) deseja?")
      leia(item)
      
      escreval("Qual a quantidade o senhor(a) gostaria?")
      leia(quantidade)
      
      se (item = 100) entao
         preco <- quantidade*7.00
         escreval("Valor a ser pago pelos",quantidade,"Cachorro quente R$=",preco:2:2)
      fimse
      
      se (item = 101) entao
         preco <- quantidade*8.00
         escreval("Valor a ser pago pelos",quantidade,"Bauru R$=",preco:2:2)
      fimse
      
      se (item = 102) entao
         preco <- quantidade*9.00
         escreval("Valor a ser pago pelos",quantidade,"X-Salada R$=",preco:2:2)
      fimse
      
      se (item = 103) entao
         preco <- quantidade*10.00
         escreval("Valor a ser pago pelos",quantidade,"Hambúrguer R$=",preco:2:2)
      fimse
      
      se (item = 104) entao
         preco <- quantidade*3.00
         escreval("Valor a ser pago pelos",quantidade,"Refrigerante (Lata) R$=",preco:2:2)
      fimse
      
Fimalgoritmo