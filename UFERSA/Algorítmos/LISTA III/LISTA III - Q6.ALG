Algoritmo "LISTA III - Q6"
Var

genero: inteiro
nascimento: inteiro
ano_atual: inteiro
ano_ingresso: inteiro
idade: inteiro
tempo_trabalho: inteiro

Inicio
      escreval("Informe seu G�nero sexsual")
      escreval("0 - FEMININO")
      escreval("1 - MASCULINO")
      leia(genero)
      
      escreval("Digite o ano atual")
      leia(ano_atual)
      
      escreval("Informe seu ano de nascimento")
      leia(nascimento)
      
      escreval("Informe em que ano voc� entrou para a empresa")
      leia(ano_ingresso)
      
      idade <- ano_atual - nascimento
      tempo_trabalho <- ano_atual - ano_ingresso
      
      se genero = 0 entao
         se (idade > 60) e (tempo_trabalho > 25) entao
            escreval("Voc� est� qualificada � aposentadoria")
            
            senao
                 escreval("Infelizmente voc� n�o qualificado � aposentadoria")
         fimse
      fimse
      
      se genero = 1 entao
         se (idade > 65) e (tempo_trabalho > 30) entao
            escreval("Voc� est� qualificado � aposentadoria")
            
            senao
                 escreval("Infelizmente voc� n�o qualificado � aposentadoria")
         fimse
      fimse

Fimalgoritmo