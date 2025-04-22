#include <stdio.h>
#include <math.h>
#include <locale.h>

long int fat(int num) {

    if (num == 0 || num == 1) {
        return 1;
    }

    long int valor = 1;

    for (int i = 1; i <= num; i++)
        valor *= i;
    return valor;

}

int comb(int n, int x) {

    int c = 0;

    c = fat(n) / (fat(n - x) * fat(x));

    return c;

}

float binomial(int n, int x, int comb, float p, float q) {

    float resultado = comb * pow(p, x) * pow(q, n - x);

    return resultado;

}

int main() {

    setlocale(LC_ALL, "Portuguese_Brazil");

    int n, x;
    float p, q;

    int continuar;

    do {

        printf("Digite o valor de n: ");
        scanf("%d", &n);

        printf("Digite o valor de x: ");
        scanf("%d", &x);

        printf("Digite o valor de p de forma percentual (sem o símbolo de %%): ");
        scanf("%f", &p);

        p /= 100;
        q = 1 - p;

        float probabilidadeIndividual = binomial(n, x, comb(n, x), p, q);

        float probabilidadeAcumulada = 0;

        for (int i = 0; i <= x; i++) {
            probabilidadeAcumulada += binomial(n, i, comb(n, i), p, q);
        }

        printf("Probabilidade Binomial Individual: %.2f %%\n", probabilidadeIndividual * 100);
        printf("Probabilidade Binomial Acumulada: %.2f %%\n\n", probabilidadeAcumulada * 100);

        printf("Deseja fazer outro cálculo?\n1- Sim\n0- Não\n");

        scanf("%d", &continuar);
        printf("\n");

    } while (continuar);



    return 0;
}
