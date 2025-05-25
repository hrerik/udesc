#include <stdio.h>

int somaImpares(int x, int y);

int main() {

    int a,b;
    printf("Digite dois numeros inteiros: ");
    scanf("%i %i", &a, &b);
    printf("%i", somaImpares(a,b));

    return 0;
}

int somaImpares(int x, int y) {
    int soma = 0;
    if (x>y) {
        int temp = x;
        x = y;
        y = temp;
    }
    if (x%2 == 0) {
        x++;
    } else {
        x += 2;
    }
    for (int i = x; i < y; i += 2) {
        soma += i;
    }
    return soma;
}
