/**
    @file principal.h
    @brief Declaracion de la clase principal
    Contiene los atributos y metodos de la clase

    @Author Caceres, Jesus. Sanchez, Christian
    @date 07/2015
*/

#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>
#include <registrar.h>
#include <reparar.h>
#include <cambiarestado.h>
#include <retirar.h>
#include <artefacto.h>
#include <bitacora.h>
#include <eliminar.h>

namespace Ui {
class principal;
}

class principal : public QMainWindow
{
    Q_OBJECT

public:
    explicit principal(QWidget *parent = 0);
    ~principal();

private slots:
    void on_Registrar_clicked();

    void on_Reparar_clicked();

    void on_CambiarEstado_clicked();

    void on_Retirar_clicked();

    void on_actionVer_bitacora_triggered();

    void on_actionEliminar_registro_triggered();

private:
    Ui::principal *ui;

};

#endif // PRINCIPAL_H
