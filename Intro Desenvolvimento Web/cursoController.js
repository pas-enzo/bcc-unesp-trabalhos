const Course = require('../models/cursoModel');

const getAllCourses = async (req, res) => {
    const courseList = await Course.findAll();
    // Faça algo aqui
    console.log(courseList);
    return res.json(courseList);
}

const getCourse = async (req, res) => {
   const courseId = req.params.id;
   const course = await Course.findByPk(courseId)
      .then(course => {
         if (course === null) {
            console.error(`Atenção: Curso ${courseId} não encontrado!`)    
         } else {
            console.error(`Curso ${courseId} encontrado!`)    
            console.log(course.nome)
         }
         return res.json(course);
      })
      .catch(error => {
        console.error(error)
      });
}

const deleteCourse = async (req, res) => {
    const courseId = req.params.id;
    const course = await Course.DeleteCourse(courseId);
    // Faça algo aqui
    console.log(course);
    return res.json(course);
}

const insertCourse = async (req, res) => {
   const course = await Course.create({
      id: req.body.id,
      nome: req.body.nome,
      sigla: req.body.sigla,
      inicio: req.body.inicio,
   })
   if (course === null) {
      console.log("Erro ao tentar inserir o curso")
   } else {
      console.log("Curso inserido: " + course);
   }
   return res.json(course);
}

module.exports = {
    getAllCourses,
    getCourse,
    deleteCourse,
    insertCourse,
};