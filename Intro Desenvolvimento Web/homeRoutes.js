const express = require("express");
const homeRouter = express.Router();

homeRouter.get('/', (req, res) => {
   res.render('home', {
      title: 'Home Page',
      nome: 'Vitor Berto',
   });
});

module.exports = homeRouter;
