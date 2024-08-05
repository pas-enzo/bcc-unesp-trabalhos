const express = require("express");
const userRouter = express.Router();
const userCtrl = require("../controllers/userController");

userRouter.get('/users', userCtrl.getAllUsers);
userRouter.get('/users/nome', userCtrl.getUser);
userRouter.delete('/users/:id', userCtrl.deleteUser);
userRouter.put('/users/:id', userCtrl.insertUser);

module.exports = userRouter;
