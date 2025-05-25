#include <stdio.h>

int somaRecursiva(int n);
int somaIterativa(int n);

int main() {

    int n = 0;

    printf("Escolha o numero de termos: ");
    scanf("%d", &n);

    printf("Soma recursiva: %d\n", somaRecursiva(n));
    printf("Soma iterativa: %d\n", somaIterativa(n));

    return 0;
}

int somaRecursiva(int n) {
    if (n <= 0) {
        return 0;
    } else {
        return n + somaRecursiva(n - 1);
    }
}

int somaIterativa(int n) {
    int soma = 0;
    for (int i = 1; i <= n; i++) {
        soma += i;
    }
    return soma;
}