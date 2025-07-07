#include <stdio.h>
#include <stdlib.h>

float *clone(float *v, int n);

int main() {

    int n;
    printf("Digite o tamanho do vetor:\n>");
    scanf("%d", &n);

    float vet[n];
    for(int i = 0; i < n; i++) {
        printf("Digite o elemento %d:\n>", i + 1);
        scanf("%f", &vet[i]);
    }

    float *copia = clone(vet, n);

    printf("\nVetor clonado:\n");
    for(int i = 0; i < n; i++)
        printf("%.2f ", copia[i]);

    free(copia);
    return 0;
}

float *clone(float *v, int n) {
    float *novo = malloc(n * sizeof(float));
    for(int i = 0; i < n; i++)
        novo[i] = v[i];
    return novo;
}
