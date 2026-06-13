const express = require('express');
const alunosRouter = require('./routes/alunoRoutes');
const disciplinasRouter = require('./routes/disciplinaRoutes');
const usuarioRoutes = require('./routes/usuarioRoutes');

const app = express();
const db = require('./models');

app.use(express.json());

app.use('/api/alunos', alunosRouter);
app.use('/api/disciplinas', disciplinasRouter);
app.use('/api/user', usuarioRoutes);
module.exports = app;

const PORTA = process.env.PORT || 3000;

app.use(express.json());

app.get('/', (req, res) => {
    res.json({
        mensagem: 'API funcionando!',
        versao: '1.0.0',
        timestamp: new Date().toISOString()
    });
});

db.sequelize.sync({ alter: true }).then(() => {
  app.listen(3000, () => console.log('Servidor rodando em http://localhost:3000'));
});