/*
5. Você vai fazer um programa para classificar os competidores segundo as suas posições.
Foram criadas 5 classes: Top 5 (1-5), Top 10 (6-10), Top 20 (11-20), Top 30 (21-30) e Top 100 (outras posições)
Faça um programa que peÃ§a a posição do competidor e indique a classe do mesmo.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(void) {

    setlocale(LC_ALL, "Portuguese_Brazil");

    int posicao;

    printf("Digite sua Posição (Entre 1 e 100): ");
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
        printf("Posição inválida!");
    }

    return 0;
}