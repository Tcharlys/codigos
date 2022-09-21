Algoritmo "LISTA III - Q4"
Var

n1, n2, resultado: inteiro

Inicio

      escreval("Digite dois números para efetuar a divisão")
      leia(n1)
      leia(n2)
      
      resultado <- n1%n2

      se resultado=0 entao
         escreval(n1,"/",n2,"=",resultado)
         escreval("É Divisível")

         senao
              se n2=0 entao
                 escreval("Esta divisão é indefinida")
              senao
                   escreval("Não é divisível")
              fimse
      fimse
Fimalgoritmo