#include <stdio.h>

int converte_string(char str[]);

int main()
{
    char str[] = "225a63";
    int num = converte_string(str);

    printf("%d", num);
    return 0;
}

int converte_string(char str[])
{
    int i = 0, resultado = 0;
    while (str[i] != 0)
    {
        if (str[i] < '0' || str[i] > '9')
        {
            printf("ERROR : Um caractere diferente de um digito foi encontrado.\n");
            return (-1);
        }

        resultado = (resultado * 10) + (str[i] - '0');
        i++;
    }

    return resultado;
}
