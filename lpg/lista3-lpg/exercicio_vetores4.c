#include <stdio.h>

void busca_todos(int v[], int n, int chave, int indices[]);

int main() {
    
    int n = 0, chave = 0;

    printf("Qual o tamanho do vetor de busca?\n> ");
    scanf("%d", &n);

    int v[n];
    int indices[n];
    printf("Digite cada elemento:\n> ");
    int elem = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &elem);
        v[i] = elem;
    }

    printf("Qual a chave de busca?\n> ");
    scanf("%d", &chave);

    busca_todos(v, n, chave, indices);

    printf("Vetor de indices:\n> [");
    for (int i = 0; i < n-1; i++)
    {
        printf("%d, ", indices[i]);
    }
    printf("%d]", indices[n-1]);
    

    return 0;
}

void busca_todos(int v[], int n, int chave, int indices[]) {
    int j = 0; //indice na 'indices' que vai indicar onde comecam os '-1'
    for (int i = 0; i < n; i++)
    {
        if (v[i] == chave)
        {
            indices[j] = i; // elemento na indices salva o indice do v[]
            j++; // vai para o proximo indice possivel de 'indices'
        }
    }
    // printf("%d", j<n);
    for (j; j < n; j++)
    {
        // printf("%d", j);
        indices[j] = -1;
        // printf("%d", indices[j]);
    }
}