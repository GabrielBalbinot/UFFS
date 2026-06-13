'use strict';

/** @type {import('sequelize-cli').Migration} */
module.exports = {
  async up(queryInterface, Sequelize) {
    await queryInterface.createTable('usuario', {
      id: {
        type: Sequelize.INTEGER, autoIncrement: true,
        primaryKey: true, allowNull: false
      },
      nome: { type: Sequelize.STRING(100), allowNull: false },
      email: { type: Sequelize.STRING(100), allowNull: false, unique: true },
      senha: {
        type: Sequelize.STRING(), allowNull: false
      },
      user_type: { type: Sequelize.INTEGER, allowNull: false },
      ativo: { type: Sequelize.BOOLEAN, defaultValue: true },
    }, { schema: 'public' });
  },
  async down(queryInterface) {
    await queryInterface.dropTable({ tableName: 'usuario', schema: 'public' });
  }
};
