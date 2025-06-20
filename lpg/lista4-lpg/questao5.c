#include <stdio.h>

void lowerCase(char str[]);

int main()
{
    char str[] = "FRaSe TEstE 123 uAu";
    lowerCase(str);

    printf("%s \n", str);

    return 0;
}

void lowerCase(char str[])
{
    for (int i = 0; str[i] != 0; i++)
    {
        if (str[i] >= 65 && str[i] <= 90)
        {
            str[i] += 32;
        }
    }
}
