USE trabalho_bd;

-- Inserir Professores
INSERT INTO Professores (idProf, nome_prof, sobre_prof, plogin, psenha, pemail, capacitacao) VALUES
(1241 ,'João', 'Silva', 'joaos', 'senha123', 'joao@example.com', 'PhD em Educação Física'),
(3594, 'Maria', 'Oliveira', 'mariao', 'senha456', 'maria@example.com', 'Mestre em Educação Física');

-- Inserir Telefones_Professores
INSERT INTO Telefones_Professores (idProf, telefone) VALUES
(1241, 123456789),
(3594, 987654321),
(1241, 111222333);

-- Inserir Alunos
INSERT INTO Alunos (idAluno, dtNasc, peso, altura, login, senha, email, nome_alu, sobre_alu) VALUES
(221026241,'2000-01-01', 70, 1.75, 'aluno1', 'senha789', 'aluno1@example.com', 'Carlos', 'Santos'),
(221026215,'1998-05-05', 65, 1.60, 'aluno2', 'senha321', 'aluno2@example.com', 'Ana', 'Silva'),
(221026826,'2002-06-10', 85, 1.80, 'aluno3', 'senha456', 'aluno3@example.com', 'Luga', 'Comes'),
(221026456,'2000-01-01', 70, 1.75, 'aluno4', 'senha457', 'aluno4@example.com', 'Jose', 'Santos'),
(221026789,'1998-05-05', 65, 1.82, 'aluno5', 'senha785', 'aluno5@example.com', 'Bruna', 'Bernabeu');

-- Inserir Telefones_Alunos
INSERT INTO Telefones_Alunos (idAluno, telefone) VALUES
(221026241, 555666777),
(221026215, 555444333),
(221026826, 555888999);

-- Inserir Planos
INSERT INTO Planos (idPlano, nome, duracao, idAluno) VALUES
(185 ,  'Basico', '2024-07-01', 221026241),
(147 ,  'Premium', '2024-12-31', 221026215),
(168 ,  'Premium', '2024-12-31', 221026826),
(190 , 'Basico', '2020-01-31', 221026456),
(200 , 'Premium', '2019-06-30', 221026789);

-- Inserir Plano_Novo
INSERT INTO Plano_Novo (idPlano) VALUES
(185);

-- Inserir Plano_Existente
INSERT INTO Plano_Existente (idPlano) VALUES
(147),
(168);

-- Inserir Planodescricao
INSERT INTO PlanoDescricao(nome, preco_mens, descricao) VALUES
('Premium', '100.0','Acesso Academia e Acompanhante Gratís Toda Sexta'),
('Basico', '50.0' ,'Acesso Academia');

-- Inserir Pagamentos
INSERT INTO Pagamentos (idPago, valorPago, forma, statuss, dtPag, idPlano) VALUES
( '1596', 50.0, 'Cartão', 'Pago', '2024-06-01', 185),
( '7532' , 0.0, 'Boleto', 'Pago', '2024-06-25', 147),
( '8523' , 100.0, 'Cartão', 'Pendente', '2023-06-05', 168);

-- Inserir Recibo
INSERT INTO Recibo (idRecibo, emissao, idPago) VALUES
('852369','2024-06-01', 1596),
('147852','2024-06-05', 8523);

-- Inserir Aulas
INSERT INTO Aulas (idAula, tipo, descricao, idProf, horario) VALUES
( '74125','Yoga', 'Sessao De diminuir Estresse', 1241, '2024-06-05 10:00:00'),
( '96325','Jiu Jitsu', 'Sparring', 3594, '2024-06-12 10:00:00'),
('21478', 'Jiu Jitsu', 'Fundamentos Basicos', 3594, '2024-06-19 08:00:00');

-- Inserir Frequenta
INSERT INTO Frequenta (idAluno, idAula) VALUES
(221026241, 74125),
(221026241, 96325),
(221026826, 74125),
(221026826, 96325),
(221026826, 21478);

-- Inserir Assinaturas
INSERT INTO Assinaturas (idAssina, dtinic, dtermin, idPlano) VALUES
( '12357', '2024-06-01', '2024-07-01', 185),
( '78951', '2024-01-01', '2024-07-31', 147),
('32159', '2023-06-01', '2024-07-31', 168),
('12345', '2019-12-25', '2020-01-31', 190),
('78965', '2018-06-01', '2019-06-30', 200);

-- Inserir Acessos na Catraca
INSERT INTO Catraca (idAcesso, tipo_entrada, dtAcesso, idAluno) VALUES
(1, TRUE, '2023-05-01 08:00:00', 221026241),
(2, FALSE, '2023-05-01 10:00:00', 221026241),
(3, TRUE, '2023-05-01 08:30:00', 221026215),
(4, FALSE, '2023-05-01 09:30:00', 221026215),
(5, TRUE, '2023-05-01 09:00:00', 221026826),
(6, FALSE, '2023-05-01 11:00:00', 221026826);

-- Inserir Progresso
INSERT INTO Progresso (idAluno, teor_gordura, massa_magra, membro_sup, membro_inf, tronco, IMC) VALUES
(221026241, 20.0, 50.0, 30.0, 30.0, 40.0, 25.0),
(221026215, 18.0, 52.0, 32.0, 32.0, 42.0, 22.0),
(221026826, 8.0,48.5, 28.0, 30.0, 45.0, 25.0);