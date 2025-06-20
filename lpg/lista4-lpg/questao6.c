#include <stdio.h>

int somente_digitos(char str[]);

int main()
{
    char str[] = "12345a6789";

    if (somente_digitos(str))
    {
        printf("A string escolhida possui somente digitos \n");
    }
    else
    {
        printf("A string escolhida possui ao menos um valor diferente de um digito \n");
    }

    return 0;
}

int somente_digitos(char str[])
{
    for (int i = 0; str[i] != 0; i++)
    {
        if (str[i] < '0' || str[i] > '9')
        {
            return 0;
        }
    }
    return 1;
}