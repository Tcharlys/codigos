Algoritmo "LISTA III - Q5"
Var

diaria: inteiro
preco: real
Inicio
      escreval("VALOR DA DIÁRIA R$200,00")
      escreval("TAXA de SERVIÇO:")
      escreval("R$4,00 por diária, Nº<7")
      escreval("R$3,60 por diária, Nº=7")
      escreval("R$3,00 por diária, Nº>7")
      escreval
      escreval("Informe quantos dias vai ficar hospedado.")
      leia(diaria)
      
      se diaria > 7 entao

         preco <- diaria*3.00
      
         escreval
         escreval("VAlOR totol da hospedagem R$",preco:2:2)
      fimse

      se diaria < 7 entao
      
         preco <- diaria*4.00
         
         escreval
         escreval("VAlOR totol da hospedagem R$",preco:2:2)
      fimse
      
      se diaria = 0 entao

         preco <- diaria*3.60
         
         escreval
         escreval("VAlOR totol da hospedagem R$",preco:2:2)
      fimse
      
Fimalgoritmo