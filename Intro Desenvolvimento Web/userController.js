const User = require('../models/userModel');

const getAllUsers = async (req, res) => {
    const userList = await User.findAll();
    const usuario = userList;
    return res.render('userView', { usuario });
}

const getUser = async (req, res) => {
    const userNome = req.params.nome;
    const user = await User.findAll({
        where: {
            nome: userNome
        }
    })
        .then(user => {
            if (user === null) {
                console.error(`Atenção: Usuário ${userNome} não encontrado!`)
            } else {
                console.error(`Usuário: ${userNome} encontrado!`)
                console.log(userNome)
            }
            return res.json(user);
        })
        .catch(error => {
            console.error(error)
        });
}

const deleteUser = async (req, res) => {
    const userNome = req.params.nome;
    const user = await User.DeleteUser(userNome);
    // Faça algo aqui
    console.log(user);
    return res.json(user);
}

const insertUser = async (req, res) => {
    const user = await User.create({
        id: req.body.id,
        nome: req.body.nome,
        email: req.body.email,
        curso: req.body.curso,
    });
    if (user === null)
        console.log("Erro ao tentar inserir usuário");
    else {
        console.log("Usuário inserido: " + user);
    }
    return res.json(user);
}

module.exports = {
    getAllUsers,
    getUser,
    deleteUser,
    insertUser,
};
