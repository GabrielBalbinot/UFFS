/*
4. ? Construa um programa que simule uma calculadora simples. Primeiro é solicitada a operação desejada +, -, / ou *, em seguida os dois operandos. Como resultado, o programa mostra o resultado da operação. O Programa é finalizado quando a operação desejada for igual à @.
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

        printf("Qual operação deseja realizar?\nAdição (+)\nSubtração (-)\nDivisão (/)\nMultiplicação (*)\nSair (@)\n");
        printf("Digite apenas o símbolo localizado ao lado da operação: ");

        scanf("%c", &operacao);

        if (operacao == '@') {
            continue;
        }

        if (operacao != '+' && operacao != '-' && operacao != '/' && operacao != '*') {
            printf("\nOperação Inválida!\n");
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