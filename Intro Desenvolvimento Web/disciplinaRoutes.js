const express = require("express");
const disciplinaRouter = express.Router();
const disciplinaCtrl = require("../controllers/disciplinaController");

disciplinaRouter.get('/disciplinas', disciplinaCtrl.getAllDisciplinas);
disciplinaRouter.get('/disciplinas/:id', disciplinaCtrl.getDisciplina);
disciplinaRouter.delete('/disciplinas/:id', disciplinaCtrl.deleteDisciplina);

module.exports = disciplinaRouter;
