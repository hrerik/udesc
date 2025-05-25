#include <stdio.h>

int main() {
    float x,y = 0;
    
    printf("Qual o x do seu ponto?\n> ");
    scanf("%f", &x);
    printf("Qual o y do seu ponto?\n> ");
    scanf("%f", &y);
    
    if (x == 0) {
        if (y == 0) {
            printf("Origem");
        }
        else {
            printf("Eixo X");
        }
    }
    else {
        if (y == 0) {
            printf("Eixo Y");
        } 
        else {
            if (x > 0) {
                if (y > 0) {
                    printf("Q1");
                }
                else {
                    printf("Q4");
                }
            }
            else {
                if (y > 0) {
                    printf("Q2");
                }
                else {
                    printf("Q3");
                }
            }
        }
    }

    return 0;
}
