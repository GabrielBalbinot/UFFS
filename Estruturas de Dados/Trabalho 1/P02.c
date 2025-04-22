/*
2. Uma loja vende produtos � vista e a prazo (pagamento 30 dias depois da compra). � vista tem um desconto de 5%
e a prazo um acr�scimo de 10%. Fa�a um programa em C que pe�a o pre�o do produto e a forma de pagamento: 1 para �
vista e 2 para a prazo. Depois apresente o pre�o final do produto.
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

    printf("Qual a forma de pagamento?\n1- � vista\n2- Parcelado\n");
    scanf("%d", &tipoDePagamento);

    if (tipoDePagamento == 1) {
        printf("O valor total do produto � R$%.2f", valorDoProduto * 0.95);
    }
    else if (tipoDePagamento == 2) {
        printf("O valor total do produto � R$ %.2f", valorDoProduto * 1.1);
    }
    else {
        printf("Forma de pagamento inv�lida.");
    }

    return 0;
}