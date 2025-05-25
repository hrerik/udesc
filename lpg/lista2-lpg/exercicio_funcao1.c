#include <stdio.h>

int tipo_triangulo(float x, float y, float z);

int main()
{

    float lado1, lado2, lado3;

    scanf("%f%f%f", &lado1, &lado2, &lado3);
    tipo_triangulo(lado1, lado2, lado3);

    return 0;
}

int tipo_triangulo(float x, float y, float z)
{

    if (x + y <= z || x + z <= y || y + z <= x)
    {
        printf("Os lados nao formam um triangulo.\n");
    }
    else if (x == y && y == z)
    {
        printf("Triangulo equilatero.\n");
    }
    else if (x == y || y == z || z == x)
    {
        printf("Triangulo isosceles.\n");
    }
    else
    {
        printf("Triangulo escaleno.\n");
    }
    return 0;
}
