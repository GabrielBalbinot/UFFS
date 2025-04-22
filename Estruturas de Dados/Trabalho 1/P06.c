/*
6. Sabendo que as faixas etárias para votação são: 18 a 70 anos voto obrigatório; 16, 17 e acima de 70 anos voto facultativo;
outras idades (ou seja, menor que 16 anos) não pode votar, crie um programa que processa essa verificação.
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
        printf("Não pode votar");
    }
    else if (idade >= 18 && idade <= 70) {
        printf("Voto obrigatório");
    }
    else {
        printf("Voto facultativo");
    }

    return 0;
}