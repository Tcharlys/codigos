Algoritmo "LISTA IV - Q4"
Var

n,i,fatorial:inteiro

Inicio
fatorial<-1

      repita
      escreval("Digite um número inteiro maior que 0")
      leia(n)
      ate(n>1)
      
      i<-n
      enquanto (i>1) faca
               fatorial<-fatorial*i
               i <- i-1
      fimenquanto
      
      escreval(n,"! = ",fatorial)
      
Fimalgoritmo