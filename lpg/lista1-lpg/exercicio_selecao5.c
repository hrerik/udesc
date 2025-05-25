#include <stdio.h>

int main() {
    int testes = 0;
    scanf("%d",&testes);
    
    for (int i = 0; i < testes; i++) {
        float media = 0;
        for (int j = 0; j < 3; j++) {
            float num = 0;
            scanf("%f", &num);
            switch (j) {
                case 0:
                    media += num/5;
                    break;
                case 1:
                    media += (3 * num)/10;
                    break;
                default:
                    media += num/2;
                    break;
            }
        }
        printf("%f\n", media);
    }
    
    return 0;
}