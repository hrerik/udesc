#include <stdio.h>

double somaFatorialRecursiva(int n);
double somaFatorialIterativa(int n);
int fatorial(int n);

int main() {

    int n;
    printf("Digite o numero de termos da soma: ");
    scanf("%d", &n);
    printf("Soma fatorial recursiva: %.6f\n", somaFatorialRecursiva(n));
    printf("Soma fatorial iterativa: %.6f\n", somaFatorialIterativa(n));
    
    return 0;
}

int fatorial(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return n * fatorial(n - 1);
    }
}

double somaFatorialRecursiva(int n) {
    return (n < 0) ? 0 : 1.0 / fatorial(n) + somaFatorialRecursiva(n - 1);
}

double somaFatorialIterativa(int n) {
    double resultado = 0.0;
    for (int i = 0; i <= n; i++) {
        int fatorial = 1;
        for (int j = 2; j <= i; j++) {
            fatorial *= j;
        }

        resultado += 1.0 / fatorial;
    }
    return resultado;
}