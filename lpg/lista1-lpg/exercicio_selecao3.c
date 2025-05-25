#include <stdio.h>

int main() {
    int inicio, final, total = 0;
    scanf("%d %d", &inicio, &final);
    
    if (final >= inicio) { // mesmo dia
        total = final - inicio;
    } 
    else { // dia seguinte
        total = 24 - (inicio - final);
    }
    
    printf("O JOGO DUROU %d HORA(S)", total);

    return 0;
}