#include <stdio.h>

void remove_char(char str[], char c);

int main()
{
    char str[] = "ManhattanConnection";
    char c = 'n';

    printf("Frase Original: '%s'\n", str);
    remove_char(str, c);

    printf("Frase Alterada: '%s'\n", str);
    return 0;
}

void remove_char(char str[], char c)
{
    int size;
    for (size = 0; str[size] != 0; size++);
    size--;

    for (int i = 0; i <= size; i++)
    {
        if (str[i] == c)
        {
            int j;
            for (j = i; j <= size; j++)
            {
                str[j] = str[j + 1];
            }
            str[j + 1] = 0;
            size--;
            i--;
        }
    }
}
