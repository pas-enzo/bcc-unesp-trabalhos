const Sequelize = require('sequelize');
const sequelize = require('../utils/database');

const Course = sequelize.define('courses', {
  id: {
    type: Sequelize.INTEGER,
    autoIncrement: true,
    allowNull: false,
    primaryKey: true
  },
  name: Sequelize.STRING,
  acronym: Sequelize.STRING,
  start: Sequelize.INTEGER
});

module.exports = Course;