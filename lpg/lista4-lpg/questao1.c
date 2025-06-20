#include<stdio.h>

int contem(char str[], char c);


int main()
{
    char s[] = "String";
    char c;
    printf("Digite um caracter: ");
    scanf("%c", &c);

    if (contem(s,c))
    {
        printf("A String tem o char!");
    }else
    {
        printf("A String nao tem o char!");
    }
    return 0;
}

int contem(char str[], char c){
    for (int i = 0; str[i] != 0 ; i++)
    {
        if (str[i] == c)
        {
            return 1;
        }
    }
    return 0;
}