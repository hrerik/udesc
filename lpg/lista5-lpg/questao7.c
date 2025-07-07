#include <stdio.h>

void min_matriz(float mat[3][4], float *pMin, int *pI, int *pJ);

int main() {

    float m[3][4];

    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 4; j++) {
            printf("Digite o elemento [%d][%d]:\n>", i, j);
            scanf("%f", &m[i][j]);
        }

    float min = 0;
    int li = 0, col = 0;

    min_matriz(m, &min, &li, &col);

    printf("\nMenor valor: %.2f", min);
    printf("\nLinha: %d", li);
    printf("\nColuna: %d", col);

    return 0;
}

void min_matriz(float mat[3][4], float *pMin, int *pI, int *pJ) {
    *pMin = mat[0][0];
    *pI = 0;
    *pJ = 0;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 4; j++) {
            if(mat[i][j] < *pMin) {
                *pMin = mat[i][j];
                *pI = i;
                *pJ = j;
            }
        }
}
