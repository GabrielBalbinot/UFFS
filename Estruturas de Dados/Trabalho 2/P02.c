/*
2. ? Fa�a um programa que simule a multiplica��o por meio de adi��es. Para tal ser�oo pedidos os dois operandos. Por exemplo se for informado 3 e 4, dever� ser calculado, usando a soma, 3?4, ou seja, 12. Este c�lculo � feito somando o primeiro valor informado por ele mesmo o n�mero de vezes representada pelo segundo n�mero. Nesse exemplo, o tr�s seria somado quatro vezes: 3+3+3+3, resultando 12.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(void) {

    setlocale(LC_ALL, "Portuguese_Brazil");

    printf("Digite o n�mero a ser multiplicado: ");
    float x;
    scanf("%f", &x);

    printf("Digite quantas vezes esse n�mero ser� multiplicado (apenas inteiros): ");

    int y;
    scanf("%d", &y);

    float produto = 0;

    for (int i = 0; i < y; i++) {

        produto += x;

    }

    printf("O produto �: %.2f", produto);

    return 0;
}