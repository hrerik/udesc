#include <stdio.h>

int palindrome(char str[]);

int main()
{
    char str[] = "ARARA";

    if (palindrome(str))
    { printf("A palavra %s eh palindrome.", str);}
    else
    { printf("A palavra %s nao eh palindrome.", str); }

    return 0;
}

int palindrome(char str[])
{
    int j;
    for (j = 0; str[j] != 0; j++);
    j--;

    for (int i = 0; i < j; i++)
    {
        if (str[i] != str[j])
        {
            return 0;
        }
        j--;
    }
    return 1;
}
