/*
6. ? Dada uma sequência de n números (um número menor ou igual à 0 finaliza a sequência), apresentar o porcentual de números informados que são maiores ou igual a 10 e menores ou igual a 20. Exemplo:
Número: 5
Número: 6
Número: 11
Número: 21
Número: 0
% entre 10 e 20: 50%

*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(void) {

    setlocale(LC_ALL, "Portuguese_Brazil");

    // n será usado para ler os números, enquanto encaixam será usado para armazenar a quantia de números que se
    // encaixam na condição do problema: são maiores ou igual a 10 e menores ou igual a 20
    int n, encaixam = 0, total = 0;

    do {

        printf("Número: ");
        scanf("%d", &n);

        if (n <= 0) {
            continue;
        }

        if (n >= 10 && n <= 20) {
            encaixam++;
        }

        total++;

    } while (n >= 0);

    int porcentagem = encaixam * 100 / total;

    printf("%% entre 10 e 20: %d%%", porcentagem);

    return 0;
}