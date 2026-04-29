const calcularPreco = (preco, formaPagamento) => {

    if (formaPagamento === '1') {
        return preco * 0.95;
    } else if (formaPagamento === '2') {
        return preco * 1.1;
    } else {
        console.warn("Forma de pagamento inválida");
        return -1;
    }
}

preco = prompt("Preço do produto: ");
formaPagamento = prompt("Forma de pagamento: ");
console.log("Preço a vista: " + calcularPreco(preco, formaPagamento));