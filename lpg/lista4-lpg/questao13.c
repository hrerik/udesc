#include <stdio.h>

void substring(char str[], int ini, int n, char sub[]);

int main()
{
    char sub[30], str[] = "Alguma coisa 123";
    int ini = 8, n = 7;

    substring(str, ini, n, sub);

    printf("'%s'\n", sub);

    return 0;
}

void substring(char str[], int ini, int n, char sub[])
{
    int len, i, j = 0;
    for (len = 0; str[len] != 0; len++)
        ;
    if (ini >= len || ini < 0 || n <= 0)
    {
        sub[0] = 0;
        return;
    }
    if (ini + n > len)
        n = len - ini;

    for (i = ini; i < n + ini; i++)
    {
        sub[j] = str[i];
        j++;
    }
    sub[i] = 0;
}