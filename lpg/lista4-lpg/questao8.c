#include <stdio.h>

void extrair_data(char str[], int *D, int *M, int *A);

int main()
{
    char str[20] = "19/06/2025";
    int D = 0, M = 0, A = 0;

    extrair_data(str, &D, &M, &A);

    printf("%d %d %d \n", D, M, A);
    return 0;
}

void extrair_data(char str[], int *D, int *M, int *A)
{
    if (str[2] != '/' || str[5] != '/')
        printf("ERRO: a data nao foi escrita de forma correta.\n");
    return;
    for (int i = 0; str[i] != 0; i++)
    {
        if (i == 2 || i == 5)
            continue;
        if (str[i] < 48 || str[i] > 57)
        {
            printf("ERRO: Um caractere diferente de um digito foi encontrado.\n");
            return;
        }
    }

    *D = ((str[0] - '0') * 10) + (str[1] - '0');
    *M = ((str[3] - '0') * 10) + (str[4] - '0');
    *A = ((str[6] - '0') * 1000) + ((str[7] - '0') * 100) + ((str[8] - '0') * 10) + (str[9] - '0');
}
