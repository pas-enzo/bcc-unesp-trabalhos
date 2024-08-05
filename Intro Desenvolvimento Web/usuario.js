const Sequelize = require('sequelize');
const sequelize = require('../util/database');
const Usuario = sequelize.define('usuarios', {
  id: {
    type: Sequelize.INTEGER,
    primaryKey: true
  },
  nome: Sequelize.STRING,
  email: Sequelize.STRING,
  curso: Sequelize.STRING
});

module.exports = Usuario;
