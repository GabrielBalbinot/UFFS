const DisciplinaModel = require("../models/disciplinaModel");

function listar(req, res) {
    const disciplina = DisciplinaModel.listarTodos(req.query);
    res.status(200).json({ total: disciplina.length, disciplina });
}

function buscar(req, res) {
    const id = parseInt(req.params.id);
    if (isNaN(id)) return res.status(400).json({ erro: "Id inválido" });
    const disciplina = DisciplinaModel.buscarPorId(id);
    if (!disciplina) return res.status(400).json({ erro: "Disciplina não encontrada" });
    res.status(200).json(disciplina);
}

function criar(req, res) {
    try {
        const novaDisciplina = DisciplinaModel.criar(req.body);
        res.status(201).set('Location', '/api/disciplina' + novaDisciplina.id).json(novaDisciplina);
    } catch (err) {
        res.status(400).json( { erro: err.message })
    }
}

function atualizar(req, res) {
    const id = parseInt(req.params.id);
    const disciplina = DisciplinaModel.atualizar(id, req.body);
    if (!disciplina) return res.status(404).json({ erro: "Disciplina não encontrado" });
    res.status(200).json(disciplina);
}

function remover(req, res) {
    const id = parseInt(req.params.id);
    const ok = DisciplinaModel.remover(id);
    if (!ok) return res.status(404).json({ erro: "Disciplina não encontrado" });
    res.status(204).send();
}

module.exports = { listar, buscar, criar, atualizar, remover };