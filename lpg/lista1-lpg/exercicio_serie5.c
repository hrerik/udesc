#include <stdio.h>

double serie_taylor_aux(int n, double ex, double term, int i) {
    return (i <= n) ? term + serie_taylor_aux(n, ex, term * ex / i, i + 1) : 0;
}

double serie_taylor(int n, double ex) {
    return serie_taylor_aux(n, ex, 1, 1);
}

int main() {
    int k;
    double x;
    
    printf("Qual o valor de x para e elevado a x?\n> ");
    scanf("%lf", &x);
    
    printf("E quantos termos gostaria de usar (para precisao)?\n> ");
    scanf("%d", &k);
    
    printf("O valor de e elevado a %.0lf (baseado na serie de Taylor, com %d termos) eh %.10lf\n", x, k, serie_taylor(k, x));

    return 0;
}
