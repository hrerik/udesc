#include<stdio.h>

void concatena(char str1[], char str2[]);

int main()
{
    char str1[20] = "Alguma ";
    char str2[20] = "Coisa a a a";

    concatena(str1,str2);
    printf("%s \n", str1);    
    return 0;
}

void concatena(char str1[], char str2[]){
    int i;
    for (i = 0; str1[i] != 0; i++);
    for (int j = 0; str2[j] != 0; j++)
    {
        str1[i] = str2[j];
        i++;
    }
}