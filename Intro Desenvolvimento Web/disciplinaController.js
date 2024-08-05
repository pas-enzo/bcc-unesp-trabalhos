const Discipline = require("../models/disciplinaModel");

const getAllDisciplines = async (req, res) => {
    const discipList = await Discipline.findAll();
    const disciplina = discipList;
    return res.render("disciplinasView", { disciplina });
};

const getDiscipline = async (req, res) => {
    const disciplinaId = req.params.id;
    const disciplina = await Discipline.findByPk(disciplinaId)
        .then(disciplina => {
            if (disciplina == null)
                console.log("Disciplina: " + disciplinaId + " não encontrada!");
            else {
                console.log("Disciplina: " + disciplinaId + " encontrada!");
            }
            return res.json(disciplina);
        })
        .catch(e => {
            console.log("Erro!");
        });
};

const deleteDiscipline = async (req, res) => {
    const disciplinaId = req.params.id;
    const disciplina = await Discipline.DeleteDisciplina(disciplinaId);
    console.log("Disciplina removida: " + disciplina);
    return res.json(disciplina);
};

module.exports = {
    getAllDisciplines,
    getDiscipline,
    deleteDiscipline,
};