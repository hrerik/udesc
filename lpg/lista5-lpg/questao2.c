#include <stdio.h>

void troca_valor(float *x, float *y);

int main() {

    float a = 0, b = 0;

    printf("Digite um valor:\n>");
    scanf("%f", &a);
    printf("Digite outro valor:\n>");
    scanf("%f", &b);

    printf("\nAntes da troca: a = %.2f, b = %.2f", a, b);

    troca_valor(&a, &b);

    printf("\nDepois da troca: a = %.2f, b = %.2f", a, b);

    return 0;
}

void troca_valor(float *x, float *y) {
    float temp = *x;
    *x = *y;
    *y = temp;
}
