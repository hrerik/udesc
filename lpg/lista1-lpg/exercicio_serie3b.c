#include <stdio.h>

double pot_um(int expoente) {
    return (expoente % 2 == 0) ? 1 : -1;
}

double valor_pi(int n) {
    int den = (2*(n-1));
    return (n > 1) ? 4.0*pot_um(n)/(den*(den+1)*(den+2)) + valor_pi(n-1) : 3;
}

int main()
{
    int k = 0;
    
    printf("Qual o numero de termos usados para calcular o valor de pi?\n>");
    scanf("%d",&k);
    
    printf("O valor de pi usando %d termos eh %.10lf", k, valor_pi(k));
    
}