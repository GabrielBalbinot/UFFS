/*
4. Fa�a um programa que pe�a 4 n�meros inteiros. Em seguida, apresente quantos n�meros informados
s�o negativos e quantos s�o positivos (considere o 0 como positivo).
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(void) {

    setlocale(LC_ALL, "Portuguese_Brazil");

    int n, pos = 0, neg = 0;

    printf("Digite quatro n�meros inteiros, um por vez quando solicitado\n");

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