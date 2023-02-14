#include <stdio.h>
#include <string.h>

/*
13.c Escreva um programa em C para contar o número de vogais e
consoantes em uma string usando um ponteiro.

Dados de teste:
Insira uma string: 
    string

Saída esperada:
Número de vogais: 1
Número de constantes: 5
*/

int main(){
    char palavra[25];
    char *QtdLetras;
    int vogais, consoantes;

    printf("Insira uma string: ");
    fgets(palavra, sizeof palavra, stdin);

    QtdLetras = palavra;
    vogais = consoantes = 0;

    while (*QtdLetras != '\0')
    {
        if(*QtdLetras == 'A' ||*QtdLetras == 'E' ||*QtdLetras == 'I' ||*QtdLetras == 'O' ||*QtdLetras == 'U' ||*QtdLetras == 'a' ||*QtdLetras == 'e' ||*QtdLetras == 'i' ||*QtdLetras == 'o' ||*QtdLetras == 'u'){
            vogais++;
        }
        else
        {
            consoantes++;
        }

        QtdLetras++;
    }
    

    printf("\nNumero de vogais: %d\n", vogais);
    printf("Numero de consoantes: %d\n", consoantes-1);

    return 0;
}