#include <stdio.h>

void nPrimeirosPrimos(int k, int n);
int ehPrimo(int n);

int main() {

    int k, n;
    printf("Digite o valor de inicial: ");
    scanf("%d", &k);
    printf("Digite quantos primos voce quer: ");
    scanf("%d", &n);
    nPrimeirosPrimos(k, n);

    return 0;
}

int ehPrimo(int n) {
    if (n < 2) return 0;
    for (int i = 2; i < n/2; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

void nPrimeirosPrimos(int k, int n) {
    while (n > 0) {
        while (!ehPrimo(k)) {
            k++;
        }
        printf("%d ", k);

        k++;
        n--;
    }
}
