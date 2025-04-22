/*
3. ? Faça um programa que peça uma valor e imprima a soma de todos os números de 1 até o valor informado. Por exemplo, se o valor informado for 6, o resultado será 21, ou seja, 1 + 2 + 3 + 4 + 5 + 6.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(void) {

    setlocale(LC_ALL, "Portuguese_Brazil");

    printf("Número: ");

    int n;
    scanf("%d", &n);

    int soma = 0;

    for (int i = 1; i <= n; i++) {
        soma += i;
    }

    printf("Soma = %d", soma);

    return 0;
}