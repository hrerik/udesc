#include <stdio.h>

void trim(char str[]);

int main()
{
    char str[] = "   Hello world :D   ";
    trim(str);

    printf("'%s'\n", str);
    return 0;
}

void trim(char str[])
{
    int start = 0, i = 0, end;

    while (str[start] == ' ')
    {
        start++;
    }

    for (end = start; str[end] != '\0'; end++)
        ;
    for (end--; str[end] == ' '; end--)
        ;

    while (start <= end)
    {
        str[i++] = str[start++];
    }

    str[i] = '\0';
}
