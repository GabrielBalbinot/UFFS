const calcularSalario = (horas, valor) => {
    salario = horas * valor;
    if (horas > 200) {
        return salario * 1.05;
    }

    return salario;
}

horas = prompt("Horas trabalhadas: ");
valor = prompt("Valor da hora: ");
console.log("Salário: " + calcularSalario(horas, valor));