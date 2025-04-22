/*
3. Façaa um programa que calcule a duração de um evento qualquer. Para tal, o programa pede
a hora de início e hora de fim (sem os minutos), as horas serão informadas de 0 a 23. Perceba
que um evento pode começar em um dia e acabar em outro. Os eventos nunca terão duração de mais de 24 horas.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(void) {

    setlocale(LC_ALL, "Portuguese_Brazil");

    int inicio, fim;

    printf("Digite a hora de início do evento sem os minutos (entre 0 e 23 ): ");
    scanf("%d", &inicio);

    printf("Digite a hora do fim do evento sem os minutos (entre 0 e 23 ): ");
    scanf("%d", &fim);

    int duracao;

    if (fim > inicio) {
        duracao = fim - inicio;
    }
    else {
        duracao = 24 - inicio + fim;
    }

    printf("Duração: %d horas", duracao);

    return 0;
}