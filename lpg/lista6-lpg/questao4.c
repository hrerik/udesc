#include <stdio.h>
#include <stdlib.h>

int main() {

    int n, x;
    printf("Digite a quantidade de numeros:\n>");
    scanf("%d", &n);

    int *v = malloc(n * sizeof(int));
    int *vp = NULL, *vn = NULL;
    int cp = 0, cn = 0;

    for(int i = 0; i < n; i++) {
        printf("Digite o elemento %d:\n>", i + 1);
        scanf("%d", &x);
        v[i] = x;
        if(x > 0) {
            vp = realloc(vp, (cp + 1) * sizeof(int));
            vp[cp++] = x;
        } else if(x < 0) {
            vn = realloc(vn, (cn + 1) * sizeof(int));
            vn[cn++] = x;
        }
        // zeros nao entram na jogada
    }

    printf("\nVetor original:\n");
    for(int i = 0; i < n; i++)
        printf("%d ", v[i]);

    printf("\n\nVetor positivos:\n");
    printf("[");
    for(int i = 0; i < cp; i++) {
        if (i == cp-1) printf("%d", vp[i]);
        else printf("%d, ", vp[i]);
    }
    printf("]");

    printf("\n\nVetor negativos:\n");
    printf("[");
    for(int i = 0; i < cn; i++) {
        if (i == cn-1) printf("%d", vn[i]);
        else printf("%d, ", vn[i]);
    }
    printf("]");

    free(v);
    free(vp);
    free(vn);
    return 0;
}
