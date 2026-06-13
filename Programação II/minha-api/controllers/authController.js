const bcrypt = require('bcrypt');
const jwt = require('jsonwebtoken');
const db = require('../models');
const { Op } = require('sequelize');
const SALT_ROUNDS = 12;

async function registrar(req, res) {
    const { nome, email, senha } = req.body;
    if (!nome || !email || !senha)
        return res.status(400).json({ erro: 'Campos obrigatórios ausentes' });
    const emailExiste = await db.Usuario.findOne({ where: { email } });
    if (emailExiste)
        return res.status(409).json({ erro: 'E-mail já cadastrado' });
    // NUNCA: await db.Usuario.create({ email, senha })
    // Sempre armazene o hash, jamais a senha em texto puro
    const senhaHash = await bcrypt.hash(senha, SALT_ROUNDS);
    const usuario = await db.Usuario.create({ nome, email, senha: senhaHash });
    // Não retorne o hash da senha na resposta
    res.status(201).json({ id: usuario.id, nome: usuario.nome, email: usuario.email });
}

async function login(req, res) {
    const { email, senha } = req.body;
    if (!email || !senha)
        return res.status(400).json({ erro: 'E-mail e senha são obrigatórios' });
    // 1. Buscar usuário pelo e-mail
    const usuario = await db.Usuario.findOne({ where: { email } });
    // 2. Verificar existência e senha com tempo constante
    // Mesmo que o usuário não exista, chamamos bcrypt.compare com um hash fictício
    // para evitar que o tempo de resposta revele se o e-mail está cadastrado.
    const hashFicticio = '$2b$12$invalidhashinvalidhashinvalidhashinvalidhashinvali';
    const senhaValida = await bcrypt.compare(senha, usuario?.senha ?? hashFicticio);

    if (!usuario || !senhaValida)
        return res.status(401).json({ erro: 'Credenciais inválidas' });
    // Não revele se o e-mail existe: use sempre a mesma mensagem de erro
    // 3. Emitir access token
    const token = jwt.sign(
        { id: usuario.id, role: usuario.role },
        process.env.JWT_SECRET,
        { expiresIn: process.env.JWT_EXPIRES_IN || '15m' }
    );
    res.status(200).json({ token });
}

module.exports = { registrar, login };