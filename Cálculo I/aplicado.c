#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

double f(double x) {
    return pow(x, 4) + sqrt(x) - 2 * x - 4;
}


int main(void) {

    setlocale(LC_ALL, "Portuguese_Brazil");
    setlocale(LC_NUMERIC, "C");

    double a, b, erro = 0.1;

    printf("A fun��oo utilizada para o programa ser�: f(x) = x^4 + raiz(x) - 2x - 4\n");
    printf("Respeitando o dom�nio da fun��o, digite dois n�meros separados por espa�o tais que ambos sejam >= 0: ");
    scanf("%lf %lf", &a, &b);

    while (a < 0) {


        printf("O valor de A n�o pode ser negativo.\nDigite outro valor para A: ");
        scanf("%lf", &a);
    }

    while (b < 0) {
        printf("O valor de B n�o pode ser negativo.\nDigite outro valor para B: ");
        scanf("%lf", &b);
    }


    while (f(a) * f(b) > 0) {
        printf("N�o � poss�vel afirmar que existe solu��o neste intervalo, tente outros dois n�meros: ");
        scanf("%lf %lf", &a, &b);
    }

    float distancia = fabs(f(a) - f(b));

    while (distancia > erro) {

        float c = (a + b) / 2;

        if (f(a) * f(c) < 0) {
            b = c;
        }
        else if (f(b) * f(c) < 0) {
            a = c;
        }

        distancia = fabs(f(a) - f(b));
    }

    printf("A equa��o tem pelo menos uma solu��o neste intervalo [%lf, %lf]\nPressione ENTER para fechar o programa", a, b);
    getchar();
    getchar();

    return 0;
}