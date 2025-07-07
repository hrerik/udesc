#include <stdio.h>
#define PI 3.1415

void calcula_circulo(float raio, float *pPerimetro, float *pArea);

int main() {

    float r = 0, perimetro = 0, area = 0;

    printf("Digite o raio do circulo:\n>");
    scanf("%f", &r);

    calcula_circulo(r, &perimetro, &area);

    printf("\nPerimetro: %.2f", perimetro);
    printf("\nArea: %.2f", area);

    return 0;
}

void calcula_circulo(float raio, float *pPerimetro, float *pArea) {
    *pPerimetro = 2 * PI * raio;
    *pArea = PI * raio * raio;
}
