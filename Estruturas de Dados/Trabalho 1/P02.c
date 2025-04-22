/*
2. Uma loja vende produtos à vista e a prazo (pagamento 30 dias depois da compra). À vista tem um desconto de 5%
e a prazo um acréscimo de 10%. Faça um programa em C que peça o preço do produto e a forma de pagamento: 1 para à
vista e 2 para a prazo. Depois apresente o preço final do produto.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(void) {

    setlocale(LC_ALL, "Portuguese_Brazil");

    float valorDoProduto;
    int tipoDePagamento;

    printf("Digite o valor do produto: ");
    scanf("%f", &valorDoProduto);

    printf("Qual a forma de pagamento?\n1- À vista\n2- Parcelado\n");
    scanf("%d", &tipoDePagamento);

    if (tipoDePagamento == 1) {
        printf("O valor total do produto é R$%.2f", valorDoProduto * 0.95);
    }
    else if (tipoDePagamento == 2) {
        printf("O valor total do produto é R$ %.2f", valorDoProduto * 1.1);
    }
    else {
        printf("Forma de pagamento inválida.");
    }

    return 0;
}