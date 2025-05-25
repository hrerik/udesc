#include <stdio.h>

int maiorInt(int x, int y, int z);

int main() {
    
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int maior = maiorInt(a, b, c);
    printf("%d\n", maior);
    
    return 0;
}

int maiorInt(int x, int y, int z) {
    if (x > y) {
        if (x > z) {
            return x;
        } else {
            return z;
        }
    } else {
        if (y > z) {
            return y;
        } else {
            return z;
        }
    }
}
