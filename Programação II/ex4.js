const multPorAdi = (a, b) => {

    let x = 0;

    for (i=0; i < b; i++) {
        x += a;
    }

    return x;
}

a = parseInt(prompt("a: "));
b = parseInt(prompt("b: "));
console.log("Resultado: " + multPorAdi(a, b));