/*
1. ? Faça um programa que peça um número e imprima os números de 1 até o número informado. Sendo que, quando chegar na metade da impressão, mostrar a mensagem Metade (a metade não precisa ser exata).
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(void) {

    setlocale(LC_ALL, "Portuguese_Brazil");

    printf("Número: ");

    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {

        printf("%d\n", i);

        if (i == n / 2) {
            printf("Metade\n");
        }

    }

    return 0;
}