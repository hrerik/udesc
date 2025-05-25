#include <stdio.h>

int compara(float a[], float b[], int n);

int main() {
    
    int n;
    printf("Digite o tamanho dos vetores: ");
    scanf("%d", &n);

    float a[n], b[n];
    printf("Digite os elementos do vetor A:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &a[i]);
    }
    printf("Digite os elementos do vetor B:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &b[i]);
    }
    
    if (compara(a, b, n))
    {
        printf("Os vetores A e B sao iguais.\n");
    }
    else
    {
        printf("Os vetores A e B sao diferentes.\n");
    }

    return 0;
}

int compara(float a[], float b[], int n) {
    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])
        {
            return 0;
        }
    }
    return 1;    
}