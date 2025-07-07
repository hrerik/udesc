#include <stdio.h>

void inc_dec (int *a, int *b);

int main() {

    int a = 0,b = 0;

    printf("Digite um numero:\n>");
    scanf("%d", &a);
    printf("Digite outro numero:\n>");
    scanf("%d", &b);

    inc_dec(&a,&b);

    printf("\nO primeiro numero incrementado eh %d", a);
    printf("\nO segundo numero decrementado eh %d", b);

    return 0;
}

void inc_dec(int *a, int *b) {(*a)++;(*b)--;}
