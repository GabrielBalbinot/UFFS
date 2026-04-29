let lados = prompt().split(' ').map(Number);
lados.sort((a, b) => a-b);
let a = parseFloat(lados[2]), b = parseFloat(lados[1]), c = parseFloat(lados[0]);

if (a >= b + c) {
    console.log("NAO FORMA TRIANGULO");
} else {

    if (a * a === b * b + c * c) {
        console.log("TRIANGULO RETANGULO");
    } else if (a * a > b * b + c * c) {
        console.log("TRIANGULO OBTUSANGULO");
    } else if (a * a < b * b + c * c) {
        console.log("TRIANGULO ACUTANGULO");
    }

    if (a === b && b === c) {
        console.log("TRIANGULO EQUILATERO");
    } else if (a === b || b === c || a === c) {
        console.log("TRIANGULO ISOSCELES");
    }

}