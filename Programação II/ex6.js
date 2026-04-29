    const maioresQueZero = (array) => {

        let maiores = 0;

        for (i of array) {
            if (i >= 10 && i <= 20) {
                maiores++;
            }
        }

        return maiores / array.length;

    }


    const arr= []

    let n = parseInt(prompt());

    while (n > 0) {
        n = parseInt(prompt());
        arr.push(n);

    }

    console.log("% entre 10 e 20: " + maioresQueZero(arr).toFixed(2) * 100 + "%");