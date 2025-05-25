#include <stdio.h>

float serie_harmonica(int n) {
    return (n > 1) ? 1.0/n + serie_harmonica(n-1) : 1;
}

int main()
{
    int k = 0;

    printf("Qual o numero de termos da serie harmonica?\n>");
    scanf("%d", &k);

    printf("O resultado da serie harmonica de %d termos eh %f", k, serie_harmonica(k));
}