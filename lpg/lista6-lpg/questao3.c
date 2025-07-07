#include <stdio.h>
#include <stdlib.h>

int main() {

    int n, cont = 0;
    printf("Digite o tamanho do vetor:\n>");
    scanf("%d", &n);

    float *v = malloc(n * sizeof(float));
    for(int i = 0; i < n; i++) {
        printf("Digite o elemento %d:\n>", i + 1);
        scanf("%f", &v[i]);
    }

    float soma = 0;
    for(int i = 0; i < n; i++)
        soma += v[i];
    float media = soma / n;

    float *maiores = malloc(n * sizeof(float));
    for(int i = 0; i < n; i++) {
        if(v[i] >= media) {
            maiores[cont] = v[i];
            cont++;
        }
    }

    maiores = realloc(maiores, cont * sizeof(float));

    printf("\nMedia: %.2f", media);
    printf("\nValores maiores ou iguais a media:\n");
    for(int i = 0; i < cont; i++)
        printf("> %.2f\n", maiores[i]);

    free(v);
    free(maiores);
    return 0;
}
