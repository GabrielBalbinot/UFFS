const express = require("express");
const router = express.Router();
const authController = require("../controllers/authController");

//router.get("/", authController.listar);
//router.get("/:id", authController.buscar);
router.post("/", authController.registrar);
router.post("/login", authController.login);    
//router.put("/:id", authController.atualizar);
//router.delete("/:id", authController.remover);

module.exports = router;