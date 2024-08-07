const Sequelize = require('sequelize');
const sequelize = require('../utils/database');

const User = sequelize.define('users', {
  id: {
    type: Sequelize.INTEGER,
    autoIncrement: true,
    allowNull: false,
    primaryKey: true
  },
  name: Sequelize.STRING,
  email: Sequelize.STRING,
  course: Sequelize.STRING
});

module.exports = User;
