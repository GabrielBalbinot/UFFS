/*
2. ? Faça um programa que simule a multiplicação por meio de adições. Para tal serãoo pedidos os dois operandos. Por exemplo se for informado 3 e 4, deverá ser calculado, usando a soma, 3?4, ou seja, 12. Este cálculo é feito somando o primeiro valor informado por ele mesmo o número de vezes representada pelo segundo número. Nesse exemplo, o três seria somado quatro vezes: 3+3+3+3, resultando 12.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(void) {

    setlocale(LC_ALL, "Portuguese_Brazil");

    printf("Digite o número a ser multiplicado: ");
    float x;
    scanf("%f", &x);

    printf("Digite quantas vezes esse número será multiplicado (apenas inteiros): ");

    int y;
    scanf("%d", &y);

    float produto = 0;

    for (int i = 0; i < y; i++) {

        produto += x;

    }

    printf("O produto é: %.2f", produto);

    return 0;
}