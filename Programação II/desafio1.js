let n, arr = [];

n = parseInt(prompt());

for (i=0; i<n; i++) {

    let x = parseInt(prompt());
    arr.push(x);

}

let resposta = true, anterior = -1; // anterior = 0 representa vale, 1 representa pico

for (i=1; i<arr.length; i++) {

    if (arr[i] < arr[i-1] && anterior === 0) {
        resposta = false;
        break;
    } else if (arr[i] > arr[i-1] && anterior === 1) {
        resposta = false;
        break;
    }

    if (anterior === 1) {
        anterior = 0;
    } else {
        anterior = 1;
    }

}

if (resposta) {
    console.log(1);
} else {
    console.log(0);
}