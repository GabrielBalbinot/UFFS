let arr = [];
let pos = 0, neg = 0;

for (i=0; i<4; i++) {

    let x = parseInt(prompt("N"+i));
    arr.push(x);

}

for (i of arr) {

    if (i < 0) {
        neg++;
    } else {
        pos++;
    }

}

console.log(pos + "(+) e " + neg + "(-)");