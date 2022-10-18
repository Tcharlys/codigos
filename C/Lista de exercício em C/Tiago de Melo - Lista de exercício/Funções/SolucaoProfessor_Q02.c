// Autor: Prof. Tiago Eugenio de Melo
// Data: 05.12.2011
// Contato: tiagodemelo@gmail.com

#include <stdio.h>

float media (float a, float b, float c) {
	float media;
	media = (a+b+c)/3;
	return media;
}

int main() {
	float nota1, nota2, nota3, resultado;
	scanf("%f %f %f", &nota1, &nota2, &nota3);
	resultado = media(nota1, nota2, nota3);
	printf("A mÃ©dia Ã© %.2f.", resultado);
	return 0;
}