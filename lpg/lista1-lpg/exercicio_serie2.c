#include <stdio.h>

double pot_um(int expoente) {
    return (expoente % 2 == 0) ? 1 : -1;
}

double serie_ln(int n) {
    return (n > 1) ? (pot_um(n+1))/n + serie_ln(n-1) : 1;
}

int main()
{
    int k = 0;
    
    printf("Qual o numero de termos da serie que converge em ln(2)?\n>");
    scanf("%d",&k);
    
    printf("A serie de %d termos resulta em %lf", k, serie_ln(k));
    
}