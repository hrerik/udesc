#include <stdio.h>

int ehDigito(char c);

int main() {
    char c;
    int i;
    printf("Digite um caractere: ");
    scanf(" %c", &c);
    if (ehDigito(c)) {
        i = c - '0';
        printf("%i\n", i);    
    }
    
    return 0;
}

int ehDigito(char c) {
    return (c >= '0' && c <= '9');
}
