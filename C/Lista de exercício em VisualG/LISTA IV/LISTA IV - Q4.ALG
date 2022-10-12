Algoritmo "LISTA IV - Q4"
Var

n, p, d: inteiro

Inicio
      escreval("Digite um Nº")
      leia(n)
      para d de 1 ate n passo 1 faca
           se (n%d=0) entao
              p<-p+1
           fimse
      fimpara
      se (p=2) entao
         escreval("o Nº é primo")
      senao
           escreval("O Nº não é primo")
      fimse

Fimalgoritmo