#include <stdio.h>

int main() {
    int num1 = 0, num2 = 0, i = 0, j = 0, soma = 0;
    
    scanf("%d%d", &num1, &num2);
    
    if (num2 > num1) {
        i = num1 + 1;
        j = num2;
    }
    else {
        i = num2 + 1; 
        j = num1;
    }
    
    if (i % 2 == 0) i++;
    for (; i < j; i += 2) {
        soma += i;
    }
    
    printf("%d", soma);
    
    return 0;
}