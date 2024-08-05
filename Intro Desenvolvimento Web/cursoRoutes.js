const express = require("express");
const cursoRouter = express.Router();
const cursoCtrl = require("../controllers/cursoController");

cursoRouter.get('/cursos', cursoCtrl.getAllCursos);
cursoRouter.get('/cursos/:id', cursoCtrl.getCurso);
cursoRouter.delete('/cursos/:id', cursoCtrl.deleteCurso);

module.exports = cursoRouter;
