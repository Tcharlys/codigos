Algoritmo "LISTA II - Q9"
Var

VH: real //horas de trabalho
HT: real //N� de horas trabalhadas em um m�s
PD: real //percentual de desconto do INSS

SB: real //sal�rio bruto
TD: real //toral de desconto
SL: real //sal�rio l�quido

Inicio
      escreval("Informe quantidade de horas de aula")
      leia(VH)
      
      escreval("Informe a quant�a de horas trabalhadas no m�s")
      leia(HT)
      
      escreval("Digite o percentual(%) de desconto do INSS")
      leia(PD)
      
      SB<-HT*VH
      
      TD<-(PD/100)*SB
      
      SL<-SB-TD

      escreval
      escreval("O seu Sal�rio Bruto(SB)= R$", SB:2:2)
      escreval("O total descontado para o INSS foi= R$", TD:2:2)
      escreval("O seu Sal�rio L�quido(SL)= R$", SL:2:2)
      
Fimalgoritmo