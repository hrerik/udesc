#include <stdio.h>
#include <math.h>

int main() {
    float a,b,c = 0;
    
    printf("Qual o lado A do seu triangulo?\n> ");
    scanf("%f", &a);
    printf("Qual o lado B do seu triangulo?\n> ");
    scanf("%f", &b);
    printf("Qual o lado C do seu triangulo?\n> ");
    scanf("%f", &c);
    
    if (b > a) {
        float temp = a;
        a = b;
        b = temp;
    }
    if (c > a) {
        float temp = a;
        a = c;
        c = temp;
    }
    
    if (a>=b+c) {
        printf("NAO FORMA TRIANGULO\n");
    }
    
    if (a == b && b == c) {
        printf("TRIANGULO EQUILATERO\n");
    } 
    else {
        if (a == b || b == c || c == a) {
            printf("TRIANGULO ISOSCELES\n");
        }
    }
    
    a = pow(a,2);
    b = pow(b,2);
    c = pow(c,2);
    
    if (a > b + c) {
        printf("TRIANGULO OBTUSANGULO\n");
    }
    else {
        if (a < b + c) {
            printf("TRIANGULO ACUTANGULO\n");
        }
        else {
            printf("TRIANGULO RETANGULO\n");
        }
    }

    return 0;
}
