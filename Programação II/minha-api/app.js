const express = require('express');
const alunosRouter = require('./routes/alunoRoutes');
const disciplinasRouter = require('./routes/disciplinaRoutes');
const app = express();
app.use(express.json());

app.use('/api/alunos', alunosRouter);
app.use('/api/disciplinas', disciplinasRouter);
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

app.listen(PORTA, () => {
    console.log("Servidor rodando em http://localhost:" + PORTA);
});