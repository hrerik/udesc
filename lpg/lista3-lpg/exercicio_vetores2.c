#include <stdio.h>

void fibonacci(int v[], int n);

int main()
{
    int n;
    printf("Qual o tamanho do vetor de Fibonacci? ");
    scanf("%d", &n);

    if (n < 1)
    {
        printf("O tamanho nao pode ser menos do que 0!");
    }
    else
    {
        int v[n];
        fibonacci(v, n);
        printf("Os primeiros %d numeros de Fibonacci sao:\n> [", n);
        for (int i = 0; i < n - 1; i++)
        {
            printf("%d, ", v[i]);
        }
        printf("%d]\n", v[n - 1]);
    }

    return 0;
}

void fibonacci(int v[], int n)
{
    v[0] = 0;
    if (n > 1)
    {
        v[1] = 1;
        for (int i = 2; i < n; i++)
        {
            v[i] = v[i - 1] + v[i - 2];
        }
    }
}