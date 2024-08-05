const express = require("express");
const path = require("path");
const app = express();
const PORT = 4000; 

app.set('views', path.join(__dirname, 'views')); 
app.set('view engine', 'ejs');
app.use(express.static(path.join(__dirname, 'public')));

const homeRoutes = require("./routes/homeRoutes");
const userRoutes = require("./routes/userRoutes");
const cursoRoutes = require("./routes/cursoRoutes");
const disciplinaRoutes = require("./routes/disciplinaRoutes"); 

app.use(homeRoutes);
app.use(userRoutes);
app.use(cursoRoutes);
app.use(disciplinaRoutes);

app.listen(PORT, () => {
   console.log(`Servidor rodando na porta ${PORT}`);
});
