drop database if exists uffs;
CREATE DATABASE uffs;
\c uffs;

-- ==================================
-- 1. Definição de Tipos ENUM
-- ==================================
CREATE TYPE status_presenca AS ENUM ('Presente', 'Ausente');
CREATE TYPE situacao_aluno AS ENUM ('Aprovado', 'Reprovado', 'Em Recuperação');

-- ==================================
-- 2. Tabelas sem constraints
-- ==================================

CREATE TABLE alunos (
    id_aluno SERIAL,
    matricula VARCHAR(20),
    nome VARCHAR(150),
    situacao situacao_aluno
);

CREATE TABLE disciplinas (
    id_disciplina SERIAL,
    nome VARCHAR(100)
);

CREATE TABLE notas (
    id_nota SERIAL,
    id_aluno INT,
    id_disciplina INT,
    nota NUMERIC(4,2)
);

CREATE TABLE presencas (
    id_presenca SERIAL,
    id_aluno INT,
    aula_numero INT,
    status status_presenca
);

-- ==================================
-- 3. Definição de Constraints
-- ==================================

ALTER TABLE alunos ADD CONSTRAINT pk_alunos PRIMARY KEY (id_aluno);
ALTER TABLE disciplinas ADD CONSTRAINT pk_disciplinas PRIMARY KEY (id_disciplina);
ALTER TABLE notas ADD CONSTRAINT pk_notas PRIMARY KEY (id_nota);
ALTER TABLE presencas ADD CONSTRAINT pk_presencas PRIMARY KEY (id_presenca);

ALTER TABLE alunos ADD CONSTRAINT uq_alunos_matricula UNIQUE (matricula);
ALTER TABLE disciplinas ADD CONSTRAINT uq_disciplinas_nome UNIQUE (nome);

ALTER TABLE notas ADD CONSTRAINT fk_notas_aluno FOREIGN KEY (id_aluno) REFERENCES alunos (id_aluno) ON DELETE RESTRICT;
ALTER TABLE notas ADD CONSTRAINT fk_notas_disciplina FOREIGN KEY (id_disciplina) REFERENCES disciplinas (id_disciplina) ON DELETE CASCADE;
ALTER TABLE presencas ADD CONSTRAINT fk_presencas_aluno FOREIGN KEY (id_aluno) REFERENCES alunos (id_aluno) ON DELETE CASCADE;

ALTER TABLE notas ADD CONSTRAINT ck_notas_valor CHECK (nota >= 0 AND nota <= 10);
ALTER TABLE presencas ADD CONSTRAINT ck_presencas_aula CHECK (aula_numero > 0);

-- ==================================
-- 4. Inserção de Dados
-- ==================================
INSERT INTO disciplinas (nome) VALUES 
('Banco de Dados I'), 
('Algoritmos e Programação'), 
('Estrutura de Dados'), 
('Programação Orientada a Objetos');

-- ==================================
-- 5. Inserção de Alunos, Notas e Presenças
-- ==================================
INSERT INTO alunos (matricula, nome, situacao) VALUES ('20240017556', 'ALEXANDRE TEIXEIRA DOS SANTOS', 'Em Recuperação');
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (1, 1, 2.9);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (1, 2, 7.9);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (1, 3, 4.0);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (1, 4, 3.1);
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (1, 1, 'Ausente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (1, 2, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (1, 3, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (1, 4, 'Presente');
INSERT INTO alunos (matricula, nome, situacao) VALUES ('20230003771', 'ALICE BOOSTEL LATALISA', 'Aprovado');
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (2, 1, 2.2);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (2, 2, 3.7);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (2, 3, 6.0);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (2, 4, 2.2);
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (2, 1, 'Ausente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (2, 2, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (2, 3, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (2, 4, 'Presente');
INSERT INTO alunos (matricula, nome, situacao) VALUES ('20240019990', 'ANA CAROLINA CENI BORGES', 'Em Recuperação');
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (3, 1, 4.2);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (3, 2, 9.0);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (3, 3, 8.1);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (3, 4, 3.3);
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (3, 1, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (3, 2, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (3, 3, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (3, 4, 'Presente');
INSERT INTO alunos (matricula, nome, situacao) VALUES ('2221101064', 'ANA CLÁUDIA MINELA', 'Aprovado');
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (4, 1, 2.7);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (4, 2, 2.8);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (4, 3, 8.8);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (4, 4, 6.8);
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (4, 1, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (4, 2, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (4, 3, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (4, 4, 'Presente');
INSERT INTO alunos (matricula, nome, situacao) VALUES ('20240016254', 'ANDRÉ JÚLIO SPIGOLON SPAGNOL', 'Reprovado');
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (5, 1, 2.6);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (5, 2, 4.3);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (5, 3, 7.0);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (5, 4, 9.1);
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (5, 1, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (5, 2, 'Ausente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (5, 3, 'Ausente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (5, 4, 'Presente');
INSERT INTO alunos (matricula, nome, situacao) VALUES ('20240005751', 'ANDREI MAGRIN', 'Reprovado');
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (6, 1, 9.9);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (6, 2, 8.8);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (6, 3, 8.9);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (6, 4, 5.0);
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (6, 1, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (6, 2, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (6, 3, 'Ausente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (6, 4, 'Presente');
INSERT INTO alunos (matricula, nome, situacao) VALUES ('2221101036', 'ANDREU MALESKI', 'Em Recuperação');
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (7, 1, 4.1);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (7, 2, 9.5);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (7, 3, 7.2);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (7, 4, 6.9);
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (7, 1, 'Ausente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (7, 2, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (7, 3, 'Ausente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (7, 4, 'Presente');
INSERT INTO alunos (matricula, nome, situacao) VALUES ('20240012890', 'ARTHUR KOLANKIEWICZ', 'Em Recuperação');
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (8, 1, 7.5);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (8, 2, 3.8);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (8, 3, 4.6);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (8, 4, 8.1);
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (8, 1, 'Ausente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (8, 2, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (8, 3, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (8, 4, 'Presente');
INSERT INTO alunos (matricula, nome, situacao) VALUES ('20240005582', 'BRENO FELIPE RINAS', 'Aprovado');
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (9, 1, 3.7);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (9, 2, 9.5);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (9, 3, 9.0);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (9, 4, 4.5);
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (9, 1, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (9, 2, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (9, 3, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (9, 4, 'Presente');
INSERT INTO alunos (matricula, nome, situacao) VALUES ('20240016764', 'BRENO MATTIOLLO', 'Reprovado');
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (10, 1, 3.1);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (10, 2, 8.0);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (10, 3, 6.3);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (10, 4, 8.0);
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (10, 1, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (10, 2, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (10, 3, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (10, 4, 'Presente');
INSERT INTO alunos (matricula, nome, situacao) VALUES ('20240017500', 'BRENO POGERE', 'Aprovado');
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (11, 1, 6.1);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (11, 2, 2.7);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (11, 3, 2.4);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (11, 4, 2.9);
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (11, 1, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (11, 2, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (11, 3, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (11, 4, 'Ausente');
INSERT INTO alunos (matricula, nome, situacao) VALUES ('20230000690', 'CAROLINE DE QUADROS PIAZZA', 'Reprovado');
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (12, 1, 6.8);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (12, 2, 5.7);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (12, 3, 4.0);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (12, 4, 6.4);
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (12, 1, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (12, 2, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (12, 3, 'Ausente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (12, 4, 'Presente');
INSERT INTO alunos (matricula, nome, situacao) VALUES ('20240016817', 'DANIELA DO NASCIMENTO DALLA VECCHIA', 'Reprovado');
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (13, 1, 8.1);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (13, 2, 4.7);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (13, 3, 4.3);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (13, 4, 3.3);
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (13, 1, 'Ausente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (13, 2, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (13, 3, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (13, 4, 'Presente');
INSERT INTO alunos (matricula, nome, situacao) VALUES ('20240001411', 'DAVID FAMBRE MEZADRI', 'Aprovado');
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (14, 1, 6.1);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (14, 2, 2.9);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (14, 3, 7.0);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (14, 4, 8.7);
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (14, 1, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (14, 2, 'Ausente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (14, 3, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (14, 4, 'Ausente');
INSERT INTO alunos (matricula, nome, situacao) VALUES ('20230002925', 'EDUARDA LAZZARETTI DA SILVA', 'Em Recuperação');
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (15, 1, 9.3);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (15, 2, 6.8);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (15, 3, 5.9);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (15, 4, 2.9);
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (15, 1, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (15, 2, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (15, 3, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (15, 4, 'Presente');
INSERT INTO alunos (matricula, nome, situacao) VALUES ('20240017565', 'EDUARDO AVELINO KLASSEN', 'Aprovado');
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (16, 1, 9.0);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (16, 2, 9.6);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (16, 3, 2.7);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (16, 4, 5.9);
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (16, 1, 'Ausente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (16, 2, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (16, 3, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (16, 4, 'Ausente');
INSERT INTO alunos (matricula, nome, situacao) VALUES ('20240016826', 'ELEN LETICIA PEREIRA', 'Reprovado');
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (17, 1, 9.6);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (17, 2, 3.3);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (17, 3, 6.2);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (17, 4, 6.9);
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (17, 1, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (17, 2, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (17, 3, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (17, 4, 'Presente');
INSERT INTO alunos (matricula, nome, situacao) VALUES ('20240008557', 'FELIPE JESUS DA SILVA', 'Em Recuperação');
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (18, 1, 4.5);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (18, 2, 10.0);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (18, 3, 7.2);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (18, 4, 5.5);
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (18, 1, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (18, 2, 'Ausente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (18, 3, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (18, 4, 'Presente');
INSERT INTO alunos (matricula, nome, situacao) VALUES ('20240017574', 'GABRIEL AUGUSTO WEBER', 'Em Recuperação');
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (19, 1, 6.4);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (19, 2, 6.7);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (19, 3, 2.1);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (19, 4, 7.7);
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (19, 1, 'Ausente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (19, 2, 'Ausente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (19, 3, 'Ausente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (19, 4, 'Presente');
INSERT INTO alunos (matricula, nome, situacao) VALUES ('20240019882', 'GABRIEL FRANCISCO DALL''ROSA BALBINOT', 'Em Recuperação');
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (20, 1, 3.9);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (20, 2, 7.4);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (20, 3, 3.7);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (20, 4, 3.1);
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (20, 1, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (20, 2, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (20, 3, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (20, 4, 'Presente');
INSERT INTO alunos (matricula, nome, situacao) VALUES ('20240019345', 'GABRIEL SANTOS COSTA', 'Reprovado');
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (21, 1, 3.5);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (21, 2, 2.8);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (21, 3, 5.4);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (21, 4, 5.4);
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (21, 1, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (21, 2, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (21, 3, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (21, 4, 'Presente');
INSERT INTO alunos (matricula, nome, situacao) VALUES ('2311100056', 'JOAO GABRIEL CHAVES', 'Aprovado');
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (22, 1, 2.5);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (22, 2, 7.8);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (22, 3, 8.4);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (22, 4, 2.9);
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (22, 1, 'Ausente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (22, 2, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (22, 3, 'Ausente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (22, 4, 'Ausente');
INSERT INTO alunos (matricula, nome, situacao) VALUES ('20240002508', 'JOAO LUIS ALMEIDA SANTOS', 'Reprovado');
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (23, 1, 4.0);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (23, 2, 9.4);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (23, 3, 5.5);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (23, 4, 8.9);
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (23, 1, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (23, 2, 'Ausente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (23, 3, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (23, 4, 'Presente');
INSERT INTO alunos (matricula, nome, situacao) VALUES ('20240008566', 'JOÃO VITOR DE CARVALHO', 'Aprovado');
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (24, 1, 9.4);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (24, 2, 8.8);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (24, 3, 3.3);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (24, 4, 5.9);
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (24, 1, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (24, 2, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (24, 3, 'Ausente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (24, 4, 'Presente');
INSERT INTO alunos (matricula, nome, situacao) VALUES ('20240017592', 'JONAS DE MORAES', 'Reprovado');
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (25, 1, 4.1);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (25, 2, 8.3);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (25, 3, 5.6);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (25, 4, 5.4);
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (25, 1, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (25, 2, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (25, 3, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (25, 4, 'Presente');
INSERT INTO alunos (matricula, nome, situacao) VALUES ('2121101041', 'JOSÉ VÍTOR TESSARO DE BORTOLI', 'Aprovado');
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (26, 1, 3.5);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (26, 2, 3.7);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (26, 3, 2.5);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (26, 4, 7.9);
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (26, 1, 'Ausente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (26, 2, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (26, 3, 'Ausente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (26, 4, 'Presente');
INSERT INTO alunos (matricula, nome, situacao) VALUES ('20240017609', 'KETLIN BRANDAO GONZAGA', 'Em Recuperação');
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (27, 1, 3.3);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (27, 2, 9.7);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (27, 3, 2.6);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (27, 4, 3.5);
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (27, 1, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (27, 2, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (27, 3, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (27, 4, 'Ausente');
INSERT INTO alunos (matricula, nome, situacao) VALUES ('20240013360', 'LEONARDO VITOR ROTH', 'Em Recuperação');
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (28, 1, 4.0);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (28, 2, 6.8);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (28, 3, 7.0);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (28, 4, 5.4);
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (28, 1, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (28, 2, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (28, 3, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (28, 4, 'Presente');
INSERT INTO alunos (matricula, nome, situacao) VALUES ('20240016568', 'LUCAS BERNART ALMEIDA', 'Em Recuperação');
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (29, 1, 4.5);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (29, 2, 4.1);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (29, 3, 3.0);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (29, 4, 7.2);
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (29, 1, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (29, 2, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (29, 3, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (29, 4, 'Ausente');
INSERT INTO alunos (matricula, nome, situacao) VALUES ('20240016782', 'LUCAS GALVAO SECCO', 'Em Recuperação');
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (30, 1, 10.0);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (30, 2, 10.0);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (30, 3, 2.6);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (30, 4, 3.7);
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (30, 1, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (30, 2, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (30, 3, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (30, 4, 'Presente');
INSERT INTO alunos (matricula, nome, situacao) VALUES ('20240008520', 'LUCAS LUIZ SPAGNOL', 'Reprovado');
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (31, 1, 4.3);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (31, 2, 5.5);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (31, 3, 6.3);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (31, 4, 4.4);
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (31, 1, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (31, 2, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (31, 3, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (31, 4, 'Presente');
INSERT INTO alunos (matricula, nome, situacao) VALUES ('2311101009', 'LUIZ AUGUSTO SCARSI', 'Em Recuperação');
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (32, 1, 4.4);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (32, 2, 7.3);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (32, 3, 9.5);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (32, 4, 3.1);
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (32, 1, 'Ausente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (32, 2, 'Ausente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (32, 3, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (32, 4, 'Presente');
INSERT INTO alunos (matricula, nome, situacao) VALUES ('2311100058', 'MANFREED BRITZKE', 'Em Recuperação');
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (33, 1, 3.7);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (33, 2, 4.7);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (33, 3, 7.5);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (33, 4, 8.8);
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (33, 1, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (33, 2, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (33, 3, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (33, 4, 'Ausente');
INSERT INTO alunos (matricula, nome, situacao) VALUES ('2211100070', 'MARCIO FABRÍCIO MARTINI', 'Em Recuperação');
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (34, 1, 5.4);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (34, 2, 4.2);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (34, 3, 2.0);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (34, 4, 8.2);
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (34, 1, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (34, 2, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (34, 3, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (34, 4, 'Presente');
INSERT INTO alunos (matricula, nome, situacao) VALUES ('20240016746', 'MATEUS HENRIQUE SANGALLI', 'Reprovado');
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (35, 1, 6.5);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (35, 2, 2.9);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (35, 3, 9.6);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (35, 4, 7.5);
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (35, 1, 'Ausente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (35, 2, 'Ausente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (35, 3, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (35, 4, 'Presente');
INSERT INTO alunos (matricula, nome, situacao) VALUES ('20240017627', 'MATHEUS LAZAROTTO', 'Reprovado');
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (36, 1, 3.0);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (36, 2, 4.5);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (36, 3, 9.2);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (36, 4, 8.4);
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (36, 1, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (36, 2, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (36, 3, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (36, 4, 'Presente');
INSERT INTO alunos (matricula, nome, situacao) VALUES ('20240016835', 'MIZAEL GOBBI', 'Aprovado');
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (37, 1, 4.8);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (37, 2, 6.5);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (37, 3, 9.0);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (37, 4, 9.8);
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (37, 1, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (37, 2, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (37, 3, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (37, 4, 'Ausente');
INSERT INTO alunos (matricula, nome, situacao) VALUES ('20240017510', 'MURILLO KENDY RODRIGUES TAGAMI', 'Aprovado');
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (38, 1, 9.1);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (38, 2, 2.2);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (38, 3, 7.9);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (38, 4, 4.7);
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (38, 1, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (38, 2, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (38, 3, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (38, 4, 'Presente');
INSERT INTO alunos (matricula, nome, situacao) VALUES ('20240017529', 'NIUMAR GIRARDI', 'Reprovado');
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (39, 1, 3.3);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (39, 2, 7.6);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (39, 3, 5.1);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (39, 4, 2.3);
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (39, 1, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (39, 2, 'Ausente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (39, 3, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (39, 4, 'Presente');
INSERT INTO alunos (matricula, nome, situacao) VALUES ('20240016808', 'RODRIGO MARIOTTI', 'Aprovado');
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (40, 1, 3.8);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (40, 2, 7.3);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (40, 3, 5.2);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (40, 4, 4.2);
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (40, 1, 'Ausente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (40, 2, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (40, 3, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (40, 4, 'Presente');
INSERT INTO alunos (matricula, nome, situacao) VALUES ('20230000958', 'THAIS REGINA TEDESCO ZANELLA', 'Em Recuperação');
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (41, 1, 9.8);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (41, 2, 6.3);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (41, 3, 9.5);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (41, 4, 2.9);
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (41, 1, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (41, 2, 'Ausente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (41, 3, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (41, 4, 'Presente');
INSERT INTO alunos (matricula, nome, situacao) VALUES ('2311100065', 'THAUA FERNANDO WERNER', 'Aprovado');
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (42, 1, 6.8);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (42, 2, 4.8);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (42, 3, 8.3);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (42, 4, 5.5);
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (42, 1, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (42, 2, 'Ausente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (42, 3, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (42, 4, 'Ausente');
INSERT INTO alunos (matricula, nome, situacao) VALUES ('20230001338', 'TIFFANY RAISER BOLZAN', 'Aprovado');
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (43, 1, 7.7);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (43, 2, 2.0);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (43, 3, 9.4);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (43, 4, 6.3);
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (43, 1, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (43, 2, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (43, 3, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (43, 4, 'Presente');
INSERT INTO alunos (matricula, nome, situacao) VALUES ('20240005706', 'VERONICA MARCHIORI RIBEIRO DOS SANTOS', 'Aprovado');
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (44, 1, 9.6);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (44, 2, 9.4);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (44, 3, 7.0);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (44, 4, 7.3);
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (44, 1, 'Ausente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (44, 2, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (44, 3, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (44, 4, 'Presente');
INSERT INTO alunos (matricula, nome, situacao) VALUES ('2024000570a7', 'Drop Table', 'Aprovado');
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (45, 1, 10);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (45, 2, 10);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (45, 3, 10);
INSERT INTO notas (id_aluno, id_disciplina, nota) VALUES (45, 4, 10);
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (45, 1, 'Ausente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (45, 2, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (45, 3, 'Presente');
INSERT INTO presencas (id_aluno, aula_numero, status) VALUES (45, 4, 'Presente');


