#include <stdio.h>
#include <ctype.h>
// #include <string.h>

int contem(char str[], char c);

int main()
{
    char s[] = "String";
    char c;
    printf("Digite um caracter: ");
    scanf("%c", &c);

    printf("O caracter %c aparece %d vezes! \n", c, contem(s, c));

    return 0;
}

int contem(char str[], char c)
{
    int count = 0;
    for (int i = 0; str[i] != 0; i++)
    {
        if (tolower(str[i]) == c)
        {
            count++;
            // lol
        }
    }
    return count;
}