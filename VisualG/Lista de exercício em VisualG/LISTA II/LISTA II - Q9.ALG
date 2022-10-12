Algoritmo "LISTA II - Q9"
Var

VH: real //horas de trabalho
HT: real //Nº de horas trabalhadas em um mês
PD: real //percentual de desconto do INSS

SB: real //salário bruto
TD: real //toral de desconto
SL: real //salário líquido

Inicio
      escreval("Informe quantidade de horas de aula")
      leia(VH)
      
      escreval("Informe a quantía de horas trabalhadas no mês")
      leia(HT)
      
      escreval("Digite o percentual(%) de desconto do INSS")
      leia(PD)
      
      SB<-HT*VH
      
      TD<-(PD/100)*SB
      
      SL<-SB-TD

      escreval
      escreval("O seu Salário Bruto(SB)= R$", SB:2:2)
      escreval("O total descontado para o INSS foi= R$", TD:2:2)
      escreval("O seu Salário Líquido(SL)= R$", SL:2:2)
      
Fimalgoritmo