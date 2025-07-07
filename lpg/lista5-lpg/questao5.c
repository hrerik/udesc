#include <stdio.h>

void max_min(int vet[], int tam, int *pMin, int *pMax);

int main() {

    int n = 0;
    printf("Digite o tamanho do vetor:\n>");
    scanf("%d", &n);

    int v[n];
    for(int i = 0; i < n; i++) {
        printf("Digite o elemento %d:\n>", i + 1);
        scanf("%d", &v[i]);
    }

    int min = 0, max = 0;
    max_min(v, n, &min, &max);

    printf("\nMaior valor: %d", max);
    printf("\nMenor valor: %d", min);

    return 0;
}

void max_min(int vet[], int tam, int *pMin, int *pMax) {
    *pMin = *pMax = vet[0];
    for(int i = 1; i < tam; i++) {
        if(vet[i] > *pMax) *pMax = vet[i];
        if(vet[i] < *pMin) *pMin = vet[i];
    }
}
