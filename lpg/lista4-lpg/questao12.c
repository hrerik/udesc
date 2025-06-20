#include <stdio.h>

int compara(char str1[], char str2[]);

int main()
{
    char str1[] = "camizzz";
    char str2[] = "caminho";

    int result = compara(str1, str2);

    if (result == 0)
    {
        printf("as duas strings sao iguais \n");
    }
    else if (result < 0)
    {
        printf("A primeira string eh menor que a segunda.\n");
    }
    else
    {
        printf("A primeira string eh maior que a segunda.\n");
    }
    return 0;
}

int compara(char str1[], char str2[])
{
    int i;
    for (i = 0; str1[i] != 0 && str2[i] != 0; i++)
    {
        if (str1[i] < str2[i])
        {
            return -1;
        }
        else if (str1[i] > str2[i])
        {
            return 1;
        }
    }
    if (str1[i] == 0 && str2[i] != 0)
    {
        return -1;
    }
    else if (str2[i] == 0 && str1[i] != 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
