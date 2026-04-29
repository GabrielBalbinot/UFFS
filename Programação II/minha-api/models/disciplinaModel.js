let disciplinas = [
    { id: 1, nome: "Programação II", codigo: "GEX613", professor: "Giancarlo", turno: 'N'}
];

let proximoId = 2;

function listarTodos(filtros = {}) {
    let resultado = [...disciplinas];
    if (filtros.professor) {
        resultado = resultado.filter(d => d.professor.toUpperCase() === filtros.professor.toUpperCase());
    }
    if (filtros.turno) {
        resultado = resultado.filter(d => d.turno.toUpperCase() === filtros.turno.toUpperCase());
    }
    return resultado;
}

function buscarPorId(id) {
    return disciplinas.find(d => d.id === id) || null;
}

function criar(dados) {
    if (!dados.nome || !dados.codigo || !dados.professor || !dados.turno) {
        throw new Error("Campos obrigatórios ausentes");
    }
    const existe = disciplinas.find(d => d.codigo === dados.codigo);

    if (existe) {
        throw new Error("Matrícula já cadastrada");
    }
    const novaDisciplina = {id: proximoId++, ...dados};
    disciplinas.push(novaDisciplina);
    return novaDisciplina;
}

function atualizar(id, dados) {
    const idx = disciplinas.findIndex(d => d.id === id);
    if (idx === -1) return null;
    disciplinas[idx] = { ...disciplinas[idx], ...dados, id};
    return disciplinas[idx];
}

function remover(id) {
    const idx = disciplinas.find(d => d.id === id);
    if (idx === -1) return false;
    disciplinas.splice(idx, 1);
    return true;
}

module.exports = { listarTodos, buscarPorId, criar, atualizar, remover}