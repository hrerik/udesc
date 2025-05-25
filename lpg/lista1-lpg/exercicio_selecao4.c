#include <stdio.h>

int main() {
    int par = 0, impar = 0, neg = 0, pos = 0, nums = 0;
    scanf("%d", &nums);
    
    for (int i = 0; i < nums; i++) {
        int num = 0;
        scanf("%d", &num);
        if (num % 2 == 0) {
            par++;
        }
        else {
            impar++;
        }
        if (num > 0) {
            pos++;
        } else {
            if (num < 0) {
                neg++;
            }
        }
    }
    
    printf("%d valor(es) par(es)\n", par);
    printf("%d valor(es) impar(es)\n", impar);
    printf("%d valor(es) positivo(s)\n", pos);
    printf("%d valor(es) negativo(s)\n", neg);

    return 0;
}