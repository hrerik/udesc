#include <stdio.h>

void inverte_string(char str[]);

int main()
{
    char str[] = "TEstee uau";
    inverte_string(str);

    printf("%s \n", str);

    return 0;
}

void inverte_string(char str[])
{
    char temp;
    int end, start = 0;
    for (end = 0; str[end] != 0; end++)
        ;
    end--;

    while (start < end)
    {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}
