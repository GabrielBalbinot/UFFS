const tempoDeEvento = (inicio, fim) => {

    if (inicio > fim) { 
        fim += 24;
    }
    
    return fim - inicio;

}

inicio = parseInt(prompt("Início: "));
fim = parseInt(prompt("Fim: "));
console.log("Duração: " + tempoDeEvento(inicio, fim));