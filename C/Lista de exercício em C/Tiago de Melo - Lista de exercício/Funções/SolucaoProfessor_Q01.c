#include <stdio.h>

void desenhaQuadrado (char a, int b);

int main() {
	int lado;
	char letra;
	scanf("%c", &letra);
	scanf("%d", &lado);
	desenhaQuadrado(letra, lado);
	return 0;
}

void desenhaQuadrado (char a, int b) {
	int i, j;
	for (i=0;i<b;i++) {
		for (j=0;j<b;j++) {
			printf("%c ", a);
		}
		printf("\n");
	}
}