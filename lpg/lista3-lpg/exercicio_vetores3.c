#include <stdio.h>

int soma_primos(int v[], int n);

int main()
{
    int n;
    printf("Qual o tamanho do vetor de primos? ");
    scanf("%d", &n);

    if (n < 1)
    {
        printf("O tamanho do vetor precisa ser maior do que zero!");
    }
    else
    {
        int v[n];
        printf("Soma do vetor de primos: %d", soma_primos(v, n));
    }

    return 0;
}

int soma_primos(int v[], int n)
{
    v[0] = 2;
    for (int i = 1; i < n; i++)
    {
        int num = v[i-1] + 1; // pega o proximo numero do vetor primo
        for (int j = 2; j < num; j++)
        {
            if (num % j == 0)
            {
                num++; // incrementa num pois nao eh primo
                j = 2; // volta pro inicio
            }
        }
        v[i] = num; // seta do vetor primo igual a num (que agora eh primo)
    }

    int soma = 0;
    for (int i = 0; i < n; i++)
    {
        soma += v[i];
    }
    return soma;
}