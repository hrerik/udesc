#include <stdio.h>

int pot_um(int n) {
    return (n % 2 == 0) ? 1 : -1;
}

int fat(int n) {
    return (n>0) ? n * fat(n-1) : 1;
}

double pot(double num, int ex) {
    return (ex > 0) ? num * pot(num, ex-1) : 1;
}

double cosseno(double rad, int n) {
    double acc = 1;
    for (int i = 1; i <= n; i++) {
        acc += (pot_um(i) * pot(rad,2*i)) / fat(2*i);
    }
    return acc;
}

int main() {
    double x;
    int k;

    printf("Digite o valor de x (em radianos):\n> ");
    scanf("%lf", &x);

    printf("Digite o número de termos para precisão:\n> ");
    scanf("%d", &k);

    printf("Cosseno de %.5lf com %d termos: %.10lf\n", x, k, cosseno(x, k));

    return 0;
}
