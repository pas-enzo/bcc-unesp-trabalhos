const express = require('express');
const app = express();
const port = 8081;
const sequelize = require('./util/database');
const bodyParser = require('body-parser');
const Usuario    = require('./models/usuario');
sequelize.sync({ force: true });
const cors = require("cors");
app.use(cors({
    origin: "*"
}))
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: false }));
app.post("/aluno/:id", (req,res)=>{
    console.log(req.body);
    Usuario.create(req.body);
})
app.get("/aluno", (req, res)=>{
    Usuario.findAll()
    .then(usuarios=>{
        res.send(JSON.stringify(usuarios));
    })
})
app.delete("/apaga/:id", (req,res)=>{
    Usuario.destroy({
        where: {
            id: req.params.id
        }
    });
});
app.listen(port, () => {
    console.log(`Servidor rodando em http://localhost:${port}`);
});