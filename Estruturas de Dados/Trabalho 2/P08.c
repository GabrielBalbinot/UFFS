/*
8. ? Antonio tem 1,50m e cresce 2cm por ano. Carlos tem 1,10m e cresce 3cm por ano. Fazer um programa que calcule quantos anos seriam necess�rios para que Carlos tivesse a mesma altura que Antonio. Supondo que os dois crescem todos os anos.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(void) {

    setlocale(LC_ALL, "Portuguese_Brazil");

    int alturaA = 150, ritmoA = 2;
    int alturaC = 110, ritmoC = 3;

    int anos = 0;

    while (alturaA != alturaC) {

        alturaA += ritmoA;
        alturaC += ritmoC;

        anos++;

    }

    printf("Anos: %d", anos);

    return 0;
}