/**
    @file eliminar.h
    @brief Declaracion de la clase eliminar
    Contiene los atributos y metodos de la clase

    @Author Caceres, Jesus. Sanchez, Christian
    @date 07/2015
*/

#ifndef ELIMINAR_H
#define ELIMINAR_H

#include <QDialog>

namespace Ui {
class eliminar;
}

class eliminar : public QDialog
{
    Q_OBJECT

public:
    explicit eliminar(QWidget *parent = 0);
    ~eliminar();

private slots:
    void on_abrir_eliminar_clicked();

    void on_eliminar_boton_clicked();

private:
    Ui::eliminar *ui;
};

#endif // ELIMINAR_H
