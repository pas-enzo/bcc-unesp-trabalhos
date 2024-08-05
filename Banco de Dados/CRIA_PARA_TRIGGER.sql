USE trabalho_bd;

DROP TABLE IF EXISTS PROFESSORES;
DROP TABLE IF EXISTS Telefones_Professores;
DROP TABLE IF EXISTS Alunos;
DROP TABLE IF EXISTS Telefones_Alunos;
DROP TABLE IF EXISTS Planos;
DROP TABLE IF EXISTS Plano_Novo;
DROP TABLE IF EXISTS Plano_Existente;
DROP TABLE IF EXISTS PlanoDescricao;
DROP TABLE IF EXISTS Pagamentos;
DROP TABLE IF EXISTS Recibo;
DROP TABLE IF EXISTS Aulas;
DROP TABLE IF EXISTS Frequenta;
DROP TABLE IF EXISTS Assinaturas;
DROP TABLE IF EXISTS Assinatura_Inativa;
DROP TABLE IF EXISTS Assinatura_Atrasada;
DROP TABLE IF EXISTS Assinatura_Ativa;
DROP TABLE IF EXISTS Catraca;
DROP TABLE IF EXISTS Progresso;


CREATE TABLE Professores (
  idProf INTEGER PRIMARY KEY, 
  nome_prof VARCHAR(255),
  sobre_prof VARCHAR(255),
  plogin VARCHAR(255),
  psenha VARCHAR(255),
  pemail VARCHAR(255),
  capacitacao VARCHAR(255)
);

CREATE TABLE Telefones_Professores (
  idProf INTEGER,
  telefone INTEGER,
  FOREIGN KEY (idProf) REFERENCES Professores(idProf)
);

CREATE TABLE Alunos (
  idAluno INTEGER PRIMARY KEY,
  dtNasc DATETIME,
  peso FLOAT,
  altura FLOAT,
  login VARCHAR(255),
  senha VARCHAR(255),
  email VARCHAR(255),
  nome_alu VARCHAR(255),
  sobre_alu VARCHAR(255)
  
);

CREATE TABLE Telefones_Alunos (
  idAluno INTEGER,
  telefone INTEGER,
  FOREIGN KEY (idAluno) REFERENCES Alunos(idAluno)
);

CREATE TABLE Planos (
  idPlano INTEGER PRIMARY KEY,
  nome VARCHAR(255),
  duracao DATETIME,
  idAluno INTEGER,
  FOREIGN KEY (idAluno) REFERENCES Alunos(idAluno)
);

CREATE TABLE Plano_Novo (
  idPlano INTEGER PRIMARY KEY,
  FOREIGN KEY (idPlano) REFERENCES Planos(idPlano)
);

CREATE TABLE Plano_Existente (
  idPlano INTEGER PRIMARY KEY,
  FOREIGN KEY (idPlano) REFERENCES Planos(idPlano)
);

CREATE TABLE PlanoDescricao(
	nome varchar(60) PRIMARY KEY,
    preco_mens FLOAT,
    descricao varchar(255)
    
);

CREATE TABLE Pagamentos (
  idPago INTEGER PRIMARY KEY,
  valorPago FLOAT,
  forma VARCHAR(255),
  statuss VARCHAR(255),
  dtPag DATETIME,
  idPlano INTEGER,
  FOREIGN KEY (idPlano) REFERENCES Planos(idPlano)
);

CREATE TABLE Recibo (
  idRecibo INTEGER PRIMARY KEY,
  emissao DATETIME,
  idPago INTEGER
  
);

CREATE TABLE Aulas (
  idAula INTEGER PRIMARY KEY,
  tipo VARCHAR(255),
  descricao VARCHAR(255),
  idProf INTEGER,
  horario DATETIME,
  FOREIGN KEY (idProf) REFERENCES Professores(idProf)
);

CREATE TABLE Frequenta (
  idAluno INTEGER,
  idAula INTEGER,
  FOREIGN KEY (idAluno) REFERENCES Alunos(idAluno),
  FOREIGN KEY (idAula) REFERENCES Aulas(idAula)
);

CREATE TABLE Assinaturas (
  idAssina INTEGER PRIMARY KEY,
  dtinic DATETIME,
  dtermin DATETIME,
  idPlano INTEGER,
  FOREIGN KEY (idPlano) REFERENCES Planos(idPlano)
);

CREATE TABLE Assinatura_Inativa (
  idAssina INTEGER,
  FOREIGN KEY (idAssina) REFERENCES Assinaturas(idAssina)
);

CREATE TABLE Assinatura_Ativa (
  idAssina INTEGER,
  FOREIGN KEY (idAssina) REFERENCES Assinaturas(idAssina)
);

CREATE TABLE Assinatura_Atrasada (
  idAssina INTEGER,
  FOREIGN KEY (idAssina) REFERENCES Assinaturas(idAssina)
);

CREATE TABLE Catraca (
  idAcesso INTEGER PRIMARY KEY,
  tipo_entrada BOOLEAN,
  dtAcesso DATETIME,
  idAluno INTEGER,
  FOREIGN KEY (idAluno) REFERENCES Alunos(idAluno)
);

CREATE TABLE Progresso (
  idAluno INTEGER,
  teor_gordura FLOAT,
  massa_magra FLOAT,
  membro_sup FLOAT,
  membro_inf FLOAT,
  tronco FLOAT,
  IMC FLOAT,
  FOREIGN KEY (idAluno) REFERENCES Alunos(idAluno)
);