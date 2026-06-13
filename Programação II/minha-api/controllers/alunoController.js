// src/controllers/alunoController.js
const db = require('../models'); // importa todos os models via index.js
const { Op } = require('sequelize');

async function listar(req, res) {
    const { nome, pagina = 1, porPagina = 20 } = req.query;
    const where = {};
    if (nome) where.nome = { [Op.iLike]: '%' + nome + '%' };
    const { count, rows } = await db.Aluno.findAndCountAll({
        where,
        include: [{ model: db.Curso, as: 'curso' }],
        limit: parseInt(porPagina),
        offset: (parseInt(pagina) - 1) * parseInt(porPagina),
        order: [['nome', 'ASC']],
    });
    res.status(200).json({ total: count, pagina: parseInt(pagina), alunos: rows });
}

async function buscar(req, res) {
    const id = parseInt(req.params.id);
    if (isNaN(id)) return res.status(400).json({ erro: "Id inválido" });
    const aluno = await db.Aluno.findByPk(id);
    if (!aluno) return res.status(404).json({ erro: "Aluno não encontrado" });
    res.status(200).json(aluno);
}
async function criar(req, res) {
    try {
        const aluno = await db.Aluno.create(req.body);
        res.status(201).json(aluno);
    } catch (err) {
        if (err.name === 'SequelizeValidationError' ||
            err.name === 'SequelizeUniqueConstraintError') {
            return res.status(400).json({
                erro: 'Dados inválidos',
                detalhes: err.errors?.map(e => ({ campo: e.path, mensagem: e.message }))
            });
        }
        throw err; // erro inesperado asyncHandler captura e retorna 500
    }
}

async function atualizar(req, res) {
    const id = parseInt(req.params.id);
    const [linhasAtualizadas] = await db.Aluno.update(req.body, { where: { id } });
    if (linhasAtualizadas === 0) {
        return res.status(404).json({ erro: "Aluno não encontrado" });
    }
    const aluno = await db.Aluno.findByPk(id);
    res.status(200).json(aluno);
}

async function remover(req, res) {
    const id = parseInt(req.params.id);
    const linhasRemovidas = await db.Aluno.destroy({ where: { id } });
    if (linhasRemovidas === 0) {
        return res.status(404).json({ erro: "Aluno não encontrado" });
    }
    res.status(204).send();
}



module.exports = { listar, criar, buscar, atualizar, remover };