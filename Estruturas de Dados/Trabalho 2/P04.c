/*
4. ? Construa um programa que simule uma calculadora simples. Primeiro � solicitada a opera��o desejada +, -, / ou *, em seguida os dois operandos. Como resultado, o programa mostra o resultado da opera��o. O Programa � finalizado quando a opera��o desejada for igual � @.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

float adicao(float a, float b) {
    return a + b;
}

float subtracao(float a, float b) {
    return a - b;
}

float divisao(float a, float b) {
    return a / b;
}

float multiplicacao(float a, float b) {
    return a * b;
}

float calculadora(char operacao) {

    printf("\n");

    if (operacao == '+') {

        float a, b;

        printf("Digite o primeiro valor: ");
        scanf("%f", &a);

        printf("Digite o segundo valor: ");
        scanf("%f", &b);

        return adicao(a, b);
    }

    if (operacao == '-') {

        float a, b;

        printf("Digite o primeiro valor: ");
        scanf("%f", &a);

        printf("Digite o segundo valor: ");
        scanf("%f", &b);

        return subtracao(a, b);
    }

    if (operacao == '/') {

        float a, b;

        printf("Digite o dividendo: ");
        scanf("%f", &a);

        printf("Digite o divisor: ");
        scanf("%f", &b);

        return divisao(a, b);
    }

    if (operacao == '*') {

        float a, b;

        printf("Digite o primeiro valor: ");
        scanf("%f", &a);

        printf("Digite o segundo valor: ");
        scanf("%f", &b);

        return multiplicacao(a, b);
    }

    return 0;

}

int main(void) {

    setlocale(LC_ALL, "Portuguese_Brazil");

    char operacao;

    while (operacao != '@') {

        printf("Qual opera��o deseja realizar?\nAdi��o (+)\nSubtra��o (-)\nDivis�o (/)\nMultiplica��o (*)\nSair (@)\n");
        printf("Digite apenas o s�mbolo localizado ao lado da opera��o: ");

        scanf("%c", &operacao);

        if (operacao == '@') {
            continue;
        }

        if (operacao != '+' && operacao != '-' && operacao != '/' && operacao != '*') {
            printf("\nOpera��o Inv�lida!\n");
            printf("Pressione uma tecla para continuar\n");
            getchar();
            continue;
        }

        float resultado = calculadora(operacao);

        printf("Resultado: %.2f\n", resultado);

        printf("\nPressione uma tecla para continuar\n");
        getchar();
        getchar();

    }

    return 0;
}