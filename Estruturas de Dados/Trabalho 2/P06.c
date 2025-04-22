/*
6. ? Dada uma sequ�ncia de n n�meros (um n�mero menor ou igual � 0 finaliza a sequ�ncia), apresentar o porcentual de n�meros informados que s�o maiores ou igual a 10 e menores ou igual a 20. Exemplo:
N�mero: 5
N�mero: 6
N�mero: 11
N�mero: 21
N�mero: 0
% entre 10 e 20: 50%

*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(void) {

    setlocale(LC_ALL, "Portuguese_Brazil");

    // n ser� usado para ler os n�meros, enquanto encaixam ser� usado para armazenar a quantia de n�meros que se
    // encaixam na condi��o do problema: s�o maiores ou igual a 10 e menores ou igual a 20
    int n, encaixam = 0, total = 0;

    do {

        printf("N�mero: ");
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