#include <stdio.h>

void cacula_hora(int totalMinutos, int *ph, int *pm);

int main() {

    int minutos = 0, h = 0, m = 0;

    printf("Digite os minutos passados desde meia-noite:\n>");
    scanf("%d", &minutos);

    cacula_hora(minutos, &h, &m);

    printf("\nHora atual: %02d:%02d", h, m);

    return 0;
}

void cacula_hora(int totalMinutos, int *ph, int *pm) {
    *ph = totalMinutos / 60;
    *pm = totalMinutos % 60;
}
