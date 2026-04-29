const fat = (n) => {

    if (n === 0 || n === 1) {
        return 1;
    }

    return n * fat(n-1);

}

n = parseInt(prompt("N: "));
console.log("O fatorial de " + n + " é: " + fat(n));