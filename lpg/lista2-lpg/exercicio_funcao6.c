#include <stdio.h>

int fibo(int n);

int main() {
    int n;
    printf("Qual o n-esimo termo da sequencia de Fibonacci que voce quer? ");
    scanf("%d", &n);
    printf("%d", fibo(n));

}
int fibo(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibo(n - 1) + fibo(n - 2); //nn eh POSSIVEL q era TAO simples (;-;)
    }
}
