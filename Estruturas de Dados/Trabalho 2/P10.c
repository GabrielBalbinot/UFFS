/*
10. ? Um professor gostaria de ter um programa para calcular a m�dia final de seus alunos. Para isso, ele informa a matr�cula e as 5 notas que o alunos teve durante o semestre. Ap�s informar as 5 notas, o programa imprime a matr�cula do aluno e a m�dia que obteve (m�dia aritm�tica simples). Quando o professor digitar 0 o programa finaliza e apresenta a m�dia geral da turma. Proibido colocar 5 scanf para pedir as notas. Exemplo:
Matr�cula: 22010
Nota 1: 4
Nota 2: 6
Nota 3: 6
Nota 4: 6
Nota 5: 8
Aluno: 22010  M�dia: 6.0
Matr�cula: 0
M�dia geral da turma: 6.0

*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(void) {

    setlocale(LC_ALL, "Portuguese_Brazil");

    float somaDasMedias = 0;
    int qtdAlunos = 0, matricula;

    do {

        float totalNotas = 0;

        printf("Matr�cula: ");
        scanf("%d", &matricula);

        if (matricula == 0)
            continue;

        for (int i = 0; i < 5; i++) {

            float nota;
            printf("Nota %d: ", i + 1);
            scanf("%f", &nota);
            totalNotas += nota;

        }

        float media = totalNotas / 5;
        somaDasMedias += media;

        printf("Aluno: %d  M�dia: %.1f\n\n", matricula, media);
        qtdAlunos++;

    } while (matricula != 0);

    if (qtdAlunos == 0)
        qtdAlunos++;

    printf("\nM�dia geral da turma: %.1f", somaDasMedias / qtdAlunos);

    return 0;
}