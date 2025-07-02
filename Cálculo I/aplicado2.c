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

    printf("Para este programa será utilizada a função y = (e^-x) + 2 por padrão\n\n");

    printf("Digite os valores de A e B separados por espaço: ");
    scanf("%lf %lf", &a, &b);
    printf("Digite o número de subintervalos: ");
    scanf("%d", &n);

    tamanhoDoIntervalo = (b-a) /  n;

    double x = a;    

    for (int i=0; i < n; i++) {

        double retangulo = f_de_x(x) * tamanhoDoIntervalo;
        areaTotal += retangulo;
        x += tamanhoDoIntervalo;

    }

    printf("A aproximação da região plana no intervalo [%.10g,%.10g] é: %.2lf u.m.²\n", a, b, areaTotal);

    return 0;
}