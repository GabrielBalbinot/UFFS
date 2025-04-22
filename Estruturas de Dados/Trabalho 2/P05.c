/*
5. ? Fa�a um programa para calcular o fatorial de um n�mero dado. O fatorial de um n�mero n � n � (n ? 1) � (n ? 2) � . . . � 1, por defini��o o fatorial de 0 e 1 � 1. Por exemplo, o fatorial de 5 � 120, ou seja, 5 � 4 � 3 � 2 � 1 (perceba que n�o � necess�rio fazer a �ltima multiplica��o j� que 1 � o elemento neutro da multiplica��o).
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int fat(int n) {

    if (n == 1 || n == 0) {
        return 1;
    }

    int fatorial = n;

    for (int i = n - 1; i > 1; i--) {
        fatorial *= i;
    }

    return fatorial;

}

int main(void) {

    setlocale(LC_ALL, "Portuguese_Brazil");

    printf("N�mero: ");

    int n;
    scanf("%d", &n);

    if (n < 0) {
        printf("N�o existe fatorial de n�mero negativo!");
    }
    else {
        int fatorial = fat(n);

        printf("O fatorial de %d � %d", n, fatorial);
    }

    return 0;
}