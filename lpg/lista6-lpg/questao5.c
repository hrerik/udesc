#include <stdio.h>
#include <stdlib.h>

int *uniao(int *v1, int n1, int *v2, int n2, int *p3);

int main() {

    int n1, n2;

    printf("Digite o tamanho do vetor 1:\n>");
    scanf("%d", &n1);
    int v1[n1];
    for(int i = 0; i < n1; i++) {
        printf("v1[%d]:\n>", i);
        scanf("%d", &v1[i]);
    }

    printf("Digite o tamanho do vetor 2:\n>");
    scanf("%d", &n2);
    int v2[n2];
    for(int i = 0; i < n2; i++) {
        printf("v2[%d]:\n>", i);
        scanf("%d", &v2[i]);
    }

    int tamanho_uniao = 0;
    int *vu = uniao(v1, n1, v2, n2, &tamanho_uniao);

    printf("\nUniao dos vetores:\n");
    printf("[");
    for(int i = 0; i < tamanho_uniao; i++) {
        if (i == tamanho_uniao - 1) printf("%d", vu[i]);
        else printf("%d, ", vu[i]);
    }
        
    printf("]");

    free(vu);
    return 0;
}

int *uniao(int *v1, int n1, int *v2, int n2, int *p3) {
    int *res = malloc((n1 + n2) * sizeof(int));
    int tam = 0;

    for(int i = 0; i < n1; i++)
        res[tam++] = v1[i];

    for(int i = 0; i < n2; i++) {
        int existe = 0;
        for(int j = 0; j < tam; j++)
            if(v2[i] == res[j]) {
                existe = 1;
                break;
            }
        if(!existe)
            res[tam++] = v2[i];
    }

    *p3 = tam;
    res = realloc(res, tam * sizeof(int));
    return res;
}
