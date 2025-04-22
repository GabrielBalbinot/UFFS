/*
5. Voc� vai fazer um programa para classificar os competidores segundo as suas posi��es.
Foram criadas 5 classes: Top 5 (1-5), Top 10 (6-10), Top 20 (11-20), Top 30 (21-30) e Top 100 (outras posi��es)
Fa�a um programa que peça a posi��o do competidor e indique a classe do mesmo.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(void) {

    setlocale(LC_ALL, "Portuguese_Brazil");

    int posicao;

    printf("Digite sua Posi��o (Entre 1 e 100): ");
    scanf("%d", &posicao);

    if (posicao >= 1 && posicao <= 5) {
        printf("Top 5");
    }
    else if (posicao >= 6 && posicao <= 10) {
        printf("Top 10");
    }
    else if (posicao >= 11 && posicao <= 20) {
        printf("Top 20");
    }
    else if (posicao >= 21 && posicao <= 30) {
        printf("Top 30");
    }
    else if (posicao >= 31 && posicao <= 100) {
        printf("Top 100");
    }
    else {
        printf("Posi��o inv�lida!");
    }

    return 0;
}