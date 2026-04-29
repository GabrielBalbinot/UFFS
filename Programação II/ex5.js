const somaDeGauss = (n) => {

    let x = 0;

    for (i=1; i<=n; i++) {
        x += i;
    }

    return x;
}

n = parseInt(prompt("N: "));
console.log("Resultado: " + somaDeGauss(n));