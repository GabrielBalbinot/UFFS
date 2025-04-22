/*
7. ? Faça um programa que peça o salário e o número de filhos dos habitantes de uma região. Quando o salário informado for menor que zero, as entradas são finalizadas e serão apresentadas as médias salarial e de filhos informados. Exemplo:
Salário: 1500
Filhos: 2
Salário: 3245
Filhos: 2
Salário: -1
Média salários: 2372.5
Média filhos: 2.0
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(void) {

    setlocale(LC_ALL, "Portuguese_Brazil");

    int n = 0, filhos, totalFilhos = 0;
    float salario, totalSalario = 0;

    do {

        printf("Sálario: ");
        scanf("%f", &salario);

        if (salario < 0) {
            continue;
        }

        printf("Filhos: ");
        scanf("%d", &filhos);

        totalSalario = totalSalario + salario * filhos;
        totalFilhos += filhos;
        n++;

    } while (salario > 0);

    float mediaFilhos = (float)totalFilhos / n;

    printf("Média salários: %.1f\n", totalSalario / totalFilhos);
    printf("Média filhos: %.1f", mediaFilhos);

    return 0;
}