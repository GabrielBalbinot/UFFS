/* 1. Faça um programa que peça o número de horas trabalhadas e o valor da hora de um determinado funcionário.
Em seguida, calcule o salário do funcionário. Caso o funcionário tenha trabalhado mais de 200 horas,
o salário final é acrescido de 5%.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(void) {

    setlocale(LC_ALL, "Portuguese_Brazil");

    int horas;
    float valorDaHora;

    printf("Digite o total de horas de trabalho do funcionário:");
    scanf("%d", &horas);

    printf("Digite agora o valor da hora do funcionário: ");
    scanf("%f", &valorDaHora);

    float salario = (float)horas * valorDaHora;

    if (horas > 200) {
        printf("Salário: %.2f", salario * 1.05);
    }
    else {
        printf("Sálario: %.2f", salario);
    };

    return 0;
}