/*
5. ? Faça um programa para calcular o fatorial de um número dado. O fatorial de um número n é n × (n ? 1) × (n ? 2) × . . . × 1, por definição o fatorial de 0 e 1 é 1. Por exemplo, o fatorial de 5 é 120, ou seja, 5 × 4 × 3 × 2 × 1 (perceba que não é necessário fazer a última multiplicação já que 1 é o elemento neutro da multiplicação).
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

    printf("Número: ");

    int n;
    scanf("%d", &n);

    if (n < 0) {
        printf("Não existe fatorial de número negativo!");
    }
    else {
        int fatorial = fat(n);

        printf("O fatorial de %d é %d", n, fatorial);
    }

    return 0;
}