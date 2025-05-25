#include <stdio.h>

double pot_um(int expoente) {
    return (expoente % 2 == 0) ? -1 : 1;
}

double valor_pi(int n) {
    return (n > 1) ? (4*pot_um(n))/(2*n-1) + valor_pi(n-1) : 4;
}

int main()
{
    int k = 0;
    
    printf("Qual o numero de termos usados para calcular o valor de pi?\n>");
    scanf("%d",&k);
    
    printf("O valor de pi usando %d termos eh %.10lf", k, valor_pi(k));
    
}