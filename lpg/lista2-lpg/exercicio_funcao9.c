#include <stdio.h>

float serieHarmonicaRecursiva(int n);
float serieHarmonicaIterativa(int n);

int main() {

    int n;
    printf("Insira o numero de termos da série harmônica: ");
    scanf("%d", &n);
    printf("%d\n", n);
    printf("Série harmônica recursiva: %f\n", serieHarmonicaRecursiva(n));
    printf("Série harmônica iterativa: %f\n", serieHarmonicaIterativa(n));

    return 0;
}

float serieHarmonicaRecursiva(int n) {
    if (n <= 0) {
        return 0.0f;
    } else if (n == 1) {
        return 1.0f;
    } else {
        return (1.0f / n) + serieHarmonicaRecursiva(n - 1);
    }
}

float serieHarmonicaIterativa(int n) {
    float resultado = 0.0f;
    for (int i = 1; i <= n; i++) {
        resultado += 1.0f / i;
    }
    return resultado;
}