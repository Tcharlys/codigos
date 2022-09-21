#include <stdio.h>

int main() {
    double raio, area;

    scanf("%lf", &raio);

    area=3.14159*(raio*raio);

    printf("A=%.4lf", area);

    return 0;
}