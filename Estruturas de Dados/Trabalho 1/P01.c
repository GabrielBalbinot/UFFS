/* 1. Fa�a um programa que pe�a o n�mero de horas trabalhadas e o valor da hora de um determinado funcion�rio.
Em seguida, calcule o sal�rio do funcion�rio. Caso o funcion�rio tenha trabalhado mais de 200 horas,
o sal�rio final � acrescido de 5%.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(void) {

    setlocale(LC_ALL, "Portuguese_Brazil");

    int horas;
    float valorDaHora;

    printf("Digite o total de horas de trabalho do funcion�rio:");
    scanf("%d", &horas);

    printf("Digite agora o valor da hora do funcion�rio: ");
    scanf("%f", &valorDaHora);

    float salario = (float)horas * valorDaHora;

    if (horas > 200) {
        printf("Sal�rio: %.2f", salario * 1.05);
    }
    else {
        printf("S�lario: %.2f", salario);
    };

    return 0;
}