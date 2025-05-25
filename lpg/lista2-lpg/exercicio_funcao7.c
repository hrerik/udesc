#include <stdio.h>

int soma_especial(int n, int k, int x);

int main() {
    
    int n, k, x;
    printf("Quantos termos voce quer? ");
    scanf("%d", &n);
    printf("Qual o multiplo? ");
    scanf("%d", &k);
    printf("E eh a partir de qual numero? ");
    scanf("%d", &x);

    printf("%d", soma_especial(n,k,x));

    return 0;
}

int soma_especial(int n, int k, int x) {
    int soma = 0;
    while (x % k != 0) {
        x++;
    }
    for (int i = 0; i < n; i++)
    {
        soma += x + (i * k);
    }
    return soma;    
}