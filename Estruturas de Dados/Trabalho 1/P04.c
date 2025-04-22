/*
4. Faça um programa que peça 4 números inteiros. Em seguida, apresente quantos números informados
são negativos e quantos são positivos (considere o 0 como positivo).
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(void) {

    setlocale(LC_ALL, "Portuguese_Brazil");

    int n, pos = 0, neg = 0;

    printf("Digite quatro números inteiros, um por vez quando solicitado\n");

    for (int i = 0; i < 4; i++) {

        printf("N%d: ", i + 1);
        scanf("%d", &n);

        if (n < 0) {
            neg++;
        }
        else {
            pos++;
        }

    }

    printf("%d (+) e %d (-)", pos, neg);

    return 0;
}