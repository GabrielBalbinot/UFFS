/*
6. Sabendo que as faixas et�rias para vota��o s�o: 18 a 70 anos voto obrigat�rio; 16, 17 e acima de 70 anos voto facultativo;
outras idades (ou seja, menor que 16 anos) n�o pode votar, crie um programa que processa essa verifica��o.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(void) {

    setlocale(LC_ALL, "Portuguese_Brazil");

    int idade;

    printf("Digite sua idade: ");
    scanf("%d", &idade);

    if (idade < 16) {
        printf("N�o pode votar");
    }
    else if (idade >= 18 && idade <= 70) {
        printf("Voto obrigat�rio");
    }
    else {
        printf("Voto facultativo");
    }

    return 0;
}