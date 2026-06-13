"use strict";
module.exports = (sequelize, DataTypes) => {
    const Usuario = sequelize.define(
        'Usuario',
        {
            id: { type: DataTypes.INTEGER, primaryKey: true, autoIncrement: true },
            nome: {
                type: DataTypes.STRING(100),
                allowNull: false,
                validate: {
                    notEmpty: { msg: 'O nome não pode ser vazio' },
                    len: { args: [2, 100], msg: 'nome deve ter entre 2 e 100 caracteres' },
                },
            },
            email: {
                type: DataTypes.STRING(100),
                allowNull: false,
                unique: { msg: 'Este e-mail já está cadastrado' },
            },
            senha: {
                type: DataTypes.STRING(),
                allowNull: false,

            },
            ativo: { type: DataTypes.BOOLEAN, defaultValue: true },
        },
        {
            tableName: 'usuario',
            schema: 'public',
            freezeTableName: true,
            timestamps: false,
        },
    );
    /*
    Usuario.associate = function (models) {
        Usuario.belongsTo(models.Curso, { foreignKey: 'id_curso', targetKey: 'id', as: 'curso' });
        Usuario.hasMany(models.Matricula, { foreignKey: 'id_aluno', sourceKey: 'id' });
    };
    */
    return Usuario;
};


