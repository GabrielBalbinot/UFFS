/*
1. ? Fa�a um programa que pe�a um n�mero e imprima os n�meros de 1 at� o n�mero informado. Sendo que, quando chegar na metade da impress�o, mostrar a mensagem Metade (a metade n�o precisa ser exata).
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(void) {

    setlocale(LC_ALL, "Portuguese_Brazil");

    printf("N�mero: ");

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