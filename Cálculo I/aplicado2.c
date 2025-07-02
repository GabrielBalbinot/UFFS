#define _USE_MATH_DEFINES

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

double f_de_x(double x) {
    return pow(M_E, -x) + 2;
}


int main(void) {

    setlocale(LC_ALL, "Portuguese_Brazil");
    setlocale(LC_NUMERIC, "C");

    double a, b, tamanhoDoIntervalo, areaTotal = 0;
    int n;

    printf("Para este programa ser� utilizada a fun��o y = (e^-x) + 2 por padr�o\n\n");

    printf("Digite os valores de A e B separados por espa�o: ");
    scanf("%lf %lf", &a, &b);
    printf("Digite o n�mero de subintervalos: ");
    scanf("%d", &n);

    tamanhoDoIntervalo = (b-a) /  n;

    double x = a;    

    for (int i=0; i < n; i++) {

        double retangulo = f_de_x(x) * tamanhoDoIntervalo;
        areaTotal += retangulo;
        x += tamanhoDoIntervalo;

    }

    printf("A aproxima��o da regi�o plana no intervalo [%.10g,%.10g] �: %.2lf u.m.�\n", a, b, areaTotal);

    return 0;
}