const Sequelize = require('sequelize');
const sequelize = require('../utils/database');

const Discipline = sequelize.define('disciplines', {
  id: {
    type: Sequelize.INTEGER,
    autoIncrement: true,
    allowNull: false,
    primaryKey: true
  },
  description: Sequelize.STRING,
  credits: Sequelize.INTEGER,
  course: Sequelize.STRING
});

module.exports = Discipline;
