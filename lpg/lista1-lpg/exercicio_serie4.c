#include <stdio.h>

double pot(int n) {
    return (n > 0) ? n * pot(n-1) : 1;
}

double valor_e(int n) {
    return (n >= 0) ? (1/pot(n)) + valor_e(n-1) : 0;
}

int main()
{
    int k = 0;
    
    printf("Qual o numero de termos usados para calcular o valor de e?\n>");
    scanf("%d",&k);
    
    printf("O valor de e usando %d termos eh %.10lf", k, valor_e(k));
    
}