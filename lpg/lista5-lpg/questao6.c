#include <stdio.h>

void max_vetor(float vet[], int tam, float *pMax, int *pIndice);

int main() {

    int n = 0;
    printf("Digite o tamanho do vetor:\n>");
    scanf("%d", &n);

    float v[n];
    for(int i = 0; i < n; i++) {
        printf("Digite o elemento %d:\n>", i + 1);
        scanf("%f", &v[i]);
    }

    float max = 0;
    int indice = 0;
    max_vetor(v, n, &max, &indice);

    printf("\nMaior valor: %.2f", max);
    printf("\nIndice do maior valor: %d", indice);

    return 0;
}

void max_vetor(float vet[], int tam, float *pMax, int *pIndice) {
    *pMax = vet[0];
    *pIndice = 0;
    for(int i = 1; i < tam; i++) {
        if(vet[i] > *pMax) {
            *pMax = vet[i];
            *pIndice = i;
        }
    }
}
