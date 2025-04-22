/*
7. ? Fa�a um programa que pe�a o sal�rio e o n�mero de filhos dos habitantes de uma regi�o. Quando o sal�rio informado for menor que zero, as entradas s�o finalizadas e ser�o apresentadas as m�dias salarial e de filhos informados. Exemplo:
Sal�rio: 1500
Filhos: 2
Sal�rio: 3245
Filhos: 2
Sal�rio: -1
M�dia sal�rios: 2372.5
M�dia filhos: 2.0
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(void) {

    setlocale(LC_ALL, "Portuguese_Brazil");

    int n = 0, filhos, totalFilhos = 0;
    float salario, totalSalario = 0;

    do {

        printf("S�lario: ");
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

    printf("M�dia sal�rios: %.1f\n", totalSalario / totalFilhos);
    printf("M�dia filhos: %.1f", mediaFilhos);

    return 0;
}