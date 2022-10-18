// Autor: Prof. Tiago Eugenio de Melo
// Data: 14.12.2011
// Contato: tiagodemelo@gmail.com

#include <stdio.h>
#include <math.h>

int verificaRaiz (float a) {
	if (ceil(a)==a)
		return 1; //valor inteiro
	else
		return 0; //valor fracionÃ¡rio
}

int main() {
	float num, raiz;
	int flag;
	scanf("%f", &num);
	raiz = sqrt(num);
	flag = verificaRaiz (raiz);
	if (flag)
		printf("%f tem raiz quadrada inteira.", num);
	else
		printf("%f nÃ£o tem raiz quadrada inteira.", num);
	return 0;
}