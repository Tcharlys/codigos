#include <stdio.h>
#include <locale.h>
#include <math.h>
int main()
{

    float a, b, r1, r2, r3, r4, r5, r6;

    printf("Digite dois números quaisquer\n");
    scanf("%f %f", &a, &b);

    printf("A soma -> %.1f\n", r1=a+b);
    printf("O produdo do primeiro pelo quadrado do segundo -> %.1f\n", r2=a*(pow(b, 2)));
    printf("O quadrado do primeiro número -> %.1f\n", r3=pow(a, 2));
    printf("A raiz quadrada da soma dos quadrados -> %.1f\n", r4=sqrt(pow(a, 2)+pow(b, 2)));
    printf("O seno da diferença do primeiro número pelo segundo-> %.1f\n", r5=sin((a-b)));
    printf("O módulo do primeiro número -> %.1f\n\n", r6=fabs(a));

    system("pause");
    return 0;
}