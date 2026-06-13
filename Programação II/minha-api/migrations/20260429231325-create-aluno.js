'use strict';
module.exports = {
  async up(queryInterface, Sequelize) {
    await queryInterface.createTable('aluno', {
      id: {
        type: Sequelize.INTEGER, autoIncrement: true,
        primaryKey: true, allowNull: false
      },
      nome: { type: Sequelize.STRING(100), allowNull: false },
      matricula: { type: Sequelize.STRING(7), allowNull: false, unique: true },
      id_curso: {
        type: Sequelize.INTEGER, allowNull: false,
        references: { model: 'curso', key: 'id' }
      },
      ativo: { type: Sequelize.BOOLEAN, defaultValue: true },
    }, { schema: 'public' });
  },
  async down(queryInterface) {
    await queryInterface.dropTable({ tableName: 'aluno', schema: 'public' });
  }
};
