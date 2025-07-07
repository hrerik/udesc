#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *repetidor(char *s, int n);

int main() {

    char texto[100];
    int vezes;

    printf("Digite a string:\n>");
    fgets(texto, 100, stdin);
    for (int i = 0; i < 100; i++)
    {
        if(texto[i] == '\n') *(texto + i) = '\0'; // limpa '\n' do fgets, pq a vida nao eh mole ne
    }
    
    printf("Digite o numero de repeticoes:\n>");
    scanf("%d", &vezes);

    char *resultado = repetidor(texto, vezes);

    printf("\nResultado: %s", resultado);

    free(resultado);
    return 0;
}

char *repetidor(char *s, int n) {
    int tam = strlen(s);
    char *nova = malloc((tam * n + 1) * sizeof(char));
    nova[0] = '\0';
    for(int i = 0; i < n; i++)
        strcat(nova, s);
    return nova;
}
