/*
9. ? Fazer um programa que simule um campeonato com 4 times (A, B, C e D). Sera pedido o nome do primeiro time com os gols marcados e o nome do segundo time com os gols marcados. Este processo se repetirá até que seja informado um valor diferente de A, B, C ou D para o primeiro time. Ao final deverá ser apresentado o número de pontos de cada time e o campeão. Caso houver empate na primeira colocação informar que não houve campeão. Cálculo dos pontos: vitória 3 pontos, empate 1 ponto e derrota 0 ponto. Exemplo:
Time: A
Gols: 2
Time: B
Gols: 1
Time: C
Gols: 2
Time: A
Gols: 4
Time: X
Campeão: A
A: 6 pontos
B: 0 pontos
C: 0 pontos
D: 0 pontos
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void computarPontos(int* times, char time1, int golsTime1, char time2, int golsTime2) {

    int indexTime1 = time1 - 'A' - 0;
    int indexTime2 = time2 - 'A' - 0;

    if (golsTime1 > golsTime2) {
        times[indexTime1] += 3;
        return;
    }

    if (golsTime2 > golsTime1) {
        times[indexTime2] += 3;
        return;
    }

    times[indexTime1] += 1;
    times[indexTime2] += 1;

}

void decretarCampeao(int* times) {

    int A = times[0];
    int B = times[1];
    int C = times[2];
    int D = times[3];

    if (A > B && A > C && A > D) {
        printf("Campeão A");
        return;
    }

    if (B > A && B > C && B > D) {
        printf("Campeão B");
        return;
    }

    if (C > A && C > B && C > D) {
        printf("Campeão C");
        return;
    }

    if (D > A && D > B && D > C) {
        printf("Campeão D");
        return;
    }

    printf("Não houve campeão pois teve empate na primeira colocação");

}

int main(void) {

    setlocale(LC_ALL, "Portuguese_Brazil");

    int times[4] = { 0 };
    char time1, time2;
    int golsTime1, golsTime2;
    int rodada = 1;

    do {

        printf("%dª rodada\n\n", rodada);

        printf("Digite o nome do primeiro time (A, B, C ou D): ");
        scanf(" %c", &time1);

        if (!(time1 == 'A' || time1 == 'B' || time1 == 'C' || time1 == 'D')) {
            break;
        }

        printf("Digite o número de gols que o time fez: ");
        scanf("%d", &golsTime1);

        printf("Digite o nome do segundo time (A, B, C ou D): ");
        scanf(" %c", &time2);
        printf("Digite o número de gols que o time fez: ");
        scanf("%d", &golsTime2);

        rodada++;
        printf("\n\n");

        computarPontos(times, time1, golsTime1, time2, golsTime2);
    } while ((time1 == 'A' || time1 == 'B' || time1 == 'C' || time1 == 'D'));

    printf("\n");
    decretarCampeao(times);

    return 0;
}